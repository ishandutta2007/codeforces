#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define B 193
#define BL N/B+5
#define ll long long
using namespace std;
int p[N],bl[N],fl[N],fr[N],tg[BL];
ll sc[BL];
void reslv(int u){sc[u]=0;for(int i=fl[u];i<=fr[u];i++) p[i]=max(p[i],tg[u]),sc[u]+=p[i];tg[u]=0;}
void slv(int u,int v)
{
    if(v<=p[fr[u]] || v<=tg[u]) return;
    tg[u]=v;
    if(v>=p[fl[u]]){sc[u]=1ll*v*(fr[u]-fl[u]+1);return;}
    reslv(u);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    memset(fl,0x3f,sizeof(fl));
    for(int i=1;i<=n;i++) bl[i]=i/B,fl[bl[i]]=min(fl[bl[i]],i),fr[bl[i]]=max(fr[bl[i]],i);
    for(int i=1;i<=n;i++) sc[bl[i]]+=p[i];
    while(m --> 0)
    {
        int opt,v,x;
        scanf("%d%d%d",&opt,&v,&x);
        if(opt==1)
        {
            int pr=bl[v];
            for(int i=0;i<pr;i++) slv(i,x);
            for(int i=fl[pr];i<=v;i++) p[i]=max(p[i],x);
            reslv(pr);
        }
        else
        {
            int ans=0;
            int pr=bl[v];
            reslv(pr);
            for(int i=v;i<=fr[pr];i++)
            if(x>=p[i]) x-=p[i],ans++;
            for(int b=pr+1;b<=bl[n];b++)
            {
                if(sc[b]<=x) x-=sc[b],ans+=fr[b]-fl[b]+1;
                else if(x<tg[b] || x<p[fr[b]]) continue;
                else if(tg[b])
                {
                    int pl=min(fr[b]-fl[b]+1,x/tg[b]);
                    ans+=pl,x-=pl*tg[b];
                }
                else
                {
                    for(int i=fl[b];i<=fr[b] && x>=p[fr[b]];i++)
                    if(x>=p[i]) x-=p[i],ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}