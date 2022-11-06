#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
#define N 100010
#define B 833
#define BL (N/B)+5
using namespace std;
int a[N];
int bl[N],fl[N],fr[N],cnt[BL][N];
list<int>b[BL];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(fl,0x3f,sizeof(fl));
    for(int i=1;i<=n;i++) bl[i]=i/B,fl[bl[i]]=min(fl[bl[i]],i),fr[bl[i]]=max(fr[bl[i]],i);
    for(int i=1;i<=n;i++) b[bl[i]].push_back(a[i]),cnt[bl[i]][a[i]]++;
    scanf("%d",&m);
    int las=0;
    while(m --> 0)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l=(l+las-1)%n+1;r=(r+las-1)%n+1;
        if(l>r) swap(l,r);
        if(t==1)
        {
            auto u=b[bl[r]].begin();
            for(int i=fl[bl[r]];i<r;i++) ++u;
            int w=*u;
            --cnt[bl[r]][w];
            ++cnt[bl[l]][w];
            b[bl[r]].erase(u);
            u=b[bl[l]].begin();
            for(int i=fl[bl[l]];i<l;i++) ++u;
            b[bl[l]].insert(u,w);
            for (int i=bl[l];i<bl[r];i++)
            {
                int t=b[i].back();b[i].pop_back();b[i+1].push_front(t);
                --cnt[i][t];++cnt[i+1][t];
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            x=(x+las-1)%n+1;
            int ll=bl[l],rr=bl[r],ans=0;
            if(ll==rr)
            {
                auto it=b[ll].begin();
                for(int i=fl[ll];i<=r;i++,it++)
                    if (i>=l) ans+=*it==x;
            }
            else
            {
                auto it=b[ll].begin();
                for(int i=fl[ll];i<=fr[ll];i++,it++)
                    if(i>=l) ans+=*it==x;
                it=b[rr].begin();
                for(int i=fl[rr];i<=r;i++,it++) ans+=*it==x;
                for(int i=ll+1;i<rr;i++) ans+=cnt[i][x];
            }
            printf("%d\n",las=ans);
        }
    }
    return 0;
}