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
 
int as[503],n,m;
int kk(){printf("? ");for(int i=1;i<=m;++i)printf("%d ",as[i]);puts("");fflush(stdout);int t;scanf("%d",&t);return t;}
int dp[503],qh,qt,qu[503],fr[503];
int lj[503],bn,nd[503],nn,vs[503];
int main(){
    scanf("%d%d",&n,&m);
    if(m%2==0&&n%2)return puts("-1"),0;
    memset(dp,0x3f,sizeof(dp));dp[0]=0;
    qh=qt=1,qu[1]=0;
    while(qh<=qt){
        int x=qu[qh++];
        for(int i=0;i<=m&&i<=n-x;++i)if(m-i<=x){
            int t=x+i-(m-i);
            if(dp[t]>500)qu[++qt]=t,dp[t]=dp[x]+1,fr[t]=x;
            if(t==n)goto tb;
        }
    }
    tb:
    bn=dp[n];for(int i=bn,k=n;i;--i)lj[i]=k,k=fr[k];
    int re=0;
    for(int T=1;T<=bn;++T){
        int x=lj[T],ad=(x+m-nn)/2;
        memset(vs,0,sizeof(vs));for(int i=1;i<=nn;++i)vs[nd[i]]=1;
        int h=0;
        for(int i=nn+ad-x;i;--i)as[++h]=nd[nn--];
        for(int i=1;i<=n&&h!=m;++i)if(!vs[i])as[++h]=i,nd[++nn]=i;
        re^=kk();
    }
    printf("! %d\n",re);
    return 0;
}