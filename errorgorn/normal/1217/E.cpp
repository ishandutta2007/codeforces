#pragma comment(linker, "/stack:200000000") 
#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
#pragma GCC optimize("-flto-march=native")

#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
const int INF=1000000005;
const int INF2=2000000005;
int n,m;
char ch;
inline void read(int& x) {
    x = 0;
    ch = _getchar_nolock();
    while (ch&16){ //this will break when \n or   is encountered
		x = (x << 3) + (x << 1) + (ch&15);
		ch =_getchar_nolock();
	}
}
inline ii min2(ii i,ii j){
    if (i.first<j.first){
        if (i.second<j.first) return i;
        else return ii(i.first,j.first);
    }
    else{
        if (j.second<i.first) return j;
        else return ii(j.first,i.first);
    }
}
int bit; ///for querying
struct node{
    int s,e,m;
    ii bits[9];
    node *l,*r;
    node (int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
            for (int x=0;x<9;x++){
                bits[x]=min2(l->bits[x],r->bits[x]);
            }
        }
        else{
            int t1,t2;
            read(t1);
            t2=t1;
            for (int x=0;x<9;x++){
                if (t2%10) bits[x]=ii(t1,INF);
                else bits[x]=ii(INF,INF);
                t2/=10;
            }
        }
    }
    void upd(int i,int j){
        if (s==e){
            int t;
            t=j;
            for (int x=0;x<9;x++){
                if (t%10) bits[x]=ii(j,INF);
                else bits[x]=ii(INF,INF);
                t/=10;
            }
        }
        else{
            if (i<=m) l->upd(i,j);
            else r->upd(i,j);
            for (int x=0;x<9;x++){
                bits[x]=min2(l->bits[x],r->bits[x]);
            }
        }
    }
    ii query(int i,int j){ ///[i,j]
        if (i==s & j==e){
            return bits[bit];
        }
        else{
            if (j<=m) return l->query(i,j);
            else if (m<i) return r->query(i,j);
            else return min2(l->query(i,m),r->query(m+1,j));
        }
    }
} *root;
int main(){
    read(n),read(m);
    root=new node(1,n);
    int a,b,c;
    int ans;
    ii res;
    while (m--){
        read(a),read(b),read(c);
        if (a==1){
            root->upd(b,c);
        }
        else{
            ans=INF2;
            for (int x=0;x<9;x++){
                bit=x;
                res=root->query(b,c);
                if (res.second!=INF){
                    ans=min(ans,res.first+res.second);
                }
            }
            printf("%d\n",(ans==INF2)?-1:ans);
        }
    }
}