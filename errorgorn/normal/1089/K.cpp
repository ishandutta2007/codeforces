#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
struct node{
    int s,e,m;
    long long val;
    long long lazy;
    node *l,*r;
    node(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        val=-e;
        lazy=0;
        if (s!=e){
            l=new node(s,m);
            r=new node(m+1,e);
        }
    }
    void lazy_add(){
        val+=lazy;
        if (s!=e){
            l->lazy+=lazy;
            r->lazy+=lazy;
        }
        lazy=0;
    }
    long long query(int i,int j){
        lazy_add();
        if (s==i && e==j) return val;
        else if (j<=m) return l->query(i,j);
        else if (m<i) return r->query(i,j);
        else return min(l->query(i,m),r->query(m+1,j));
    }
    void update(int i,int j,long long k){
        if (s==i && e==j){
            lazy+=k;
        }
        else{
            if (j<=m) l->update(i,j,k);
            else if (m<i) r->update(i,j,k);
            else l->update(i,m,k),r->update(m+1,j,k);
            l->lazy_add(),r->lazy_add();
            val=min(l->val,r->val);
        }
    }
}*root=new node(0,1000005);
///waiting time = max(0<=i<=p) for sum(i,p)-(p-i)=pre[p]-pre[i-1]-p+i= (pre[p]-p)-(pre[i-1]-(i-1))+1
///we simply store pre[x]-x, then minimize pre[i-1]-i-1
int n;
ii arr[300005];
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    char type;
    int a,b;
    for (int x=1;x<=n;x++){
        getchar();
        type=getchar();
        if (type=='?'){
            scanf("%d",&a);
            printf("%lld\n",root->query(a,a)-root->query(0,a-1)+1);
        }
        else if (type=='+'){
            scanf("%d%d",&a,&b);
            arr[x]=ii(a,b);
            root->update(a,1000004,b);
        }
        else{
            scanf("%d",&a);
            root->update(arr[a].first,1000004,-arr[a].second);
        }
        //for (int x=0;x<10;x++) printf("%d ",root->query(x,x));
        //printf("\n");
    }
}