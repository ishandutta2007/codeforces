#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,b[mxn],ty[mxn];
int tk[mxn],tp,cb[mxn],co[mxn],be[mxn],bn,jl[mxn][2],nx[mxn];
vector<int>gg[mxn];void ga(int x,int y){gg[x].push_back(y),gg[y].push_back(x);}//printf("%d %d %d %d\n",x,b[x],y,b[y]);}
void dfs(int x,int f=0){for(int y:gg[x])if(y!=f)be[y]=be[x],co[y]=co[x]^1,dfs(y,x);}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i){int x,y;scanf("%d%d",&x,&y);if(!((x<=n)^(y<=n)))return puts("-1"),0;if(x<=n)b[x]=y,ty[x]=0;else b[y]=x,ty[y]=1;}
    for(int i=1;i<=n;++i){
        int mn=i;while(tp&&b[i]>b[tk[tp]]){int k=tk[tp--];ga(k,i);if(b[k]<b[mn])mn=k;}
        tk[++tp]=mn;
    }
    for(int i=1;i<=n;++i)if(!be[i])be[i]=++bn,dfs(i);
    for(int i=n;i;--i){
        int&x=jl[be[i]][co[i]];if(x&&b[i]<b[x])return puts("-1"),0;
        nx[i]=x,x=i;
    }
    int ans=0;
    for(int i=1;i<=bn;++i){
        int s=0,c=0;
        for(int j=jl[i][0];j;j=nx[j])++s,c+=ty[j];//,cout<<j<<' ';puts("");
        for(int j=jl[i][1];j;j=nx[j])++s,c+=ty[j]^1;//,cout<<j<<' ';puts("");
        ans+=min(c,s-c);
    }
    printf("%d\n",ans);
    return 0;
}