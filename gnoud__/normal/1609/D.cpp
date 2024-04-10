#include<bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1010;
int n,d,id[N],ans,x[N],y[N];
int root(int x) {
    return id[x]<0?x:id[x]=root(id[x]);
}
int join(int x,int y) {
    if((x=root(x))==(y=root(y))) return 0;
    id[x]+=id[y];
    id[y]=x;
    ans=max(ans,-id[x]);
    return 1;
}
main() {
    //freopen("1609.inp","r",stdin);
    n=in,d=in;
    reset(id,-1);
    ans=1;
    int ac=0;
    forinc(i,1,d) x[i]=in,y[i]=in;
    forinc(i,1,d) {
        reset(id,-1);
        int tot=0;
        forinc(j,1,i) if(!join(x[j],y[j])) tot++;
        vector<int> b;
        forinc(j,1,n) if(id[j]<0) b.pb(-id[j]);
        sort(all(b));
        while(tot&&b.size()>1) {
            int u=b.back();
            b.pop_back();
            b.back()+=u;
            tot--;
        }
        cout<<b.back()-1<<'\n';
    }
}