#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define forl(z,i,x) for(int i=z.first[x],y=z.to[i];i;i=z.nxt[i],y=z.to[i])
#define uu unsigned
#define fi first
#define se second
#define ran() ((unsigned)rand())
#define lam(z,k) [&](const z &a,const z &b){ return k; }
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define tomax(x,y) x=max(x,y)
#define tomin(x,y) x=min(x,y)
#define scanf a1234=scanf
#define fre(x) freopen(x,"r",stdin)
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}

const int mxn=1.5e5+3,mxm=303;
const long long finf=(-1ll)<<63;
int n,m;
long long dis;
int a[mxn],b[mxn],t[mxn];
long long dp[2][mxn];
int q[mxn];



int main(){
    scanf("%d%d%lld",&n,&m,&dis);for(int i=1;i<=m;++i)scanf("%d%d%d",a+i,b+i,t+i);
    for(int j=1;j<=n;++j)dp[1][j]=b[1]-abs(a[1]-j);
    for(int i=2;i<=m;++i){
        int qh=0,qt=-1,ll,rr;
        const int dd=min(dis*(t[i]-t[i-1]), (long long)n);
        
        for(int j=1;j<=n;++j){
            dp[od(i)][j]=b[i]-abs(a[i]-j);
            
            ll=max(1,j-dd),rr=min(n,j+dd);
            while(qh<=qt&&q[qh]<ll)++qh;
            for(int k=~qt?q[qt]+1:ll;k<=rr;++k){
                while(qh<=qt&&dp[ev(i)][q[qt]]<=dp[ev(i)][k])--qt;
                q[++qt]=k;
            }
            if(qh<=qt)dp[od(i)][j]+=dp[ev(i)][q[qh]];
        }
    }
    long long ans=finf;for(int i=1;i<=n;++i)ans=max(ans,dp[od(m)][i]);
    printf("%lld\n",ans);
    return 0;
}