#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
using namespace std;
int c[N],p[N],q[N];
bool can[N],vis[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&p[i]),--p[i],c[(i-p[i]+n)%n]++;
        int tt=0;
        for(int i=0;i<n;i++)
        if(c[i]>=n-m*2)
        {
            for(int j=0;j<n;j++)
                q[(j-i+n)%n]=p[j];
            int tot=0;
            for(int j=0;j<n;j++)
            if(q[j]!=j) ++tot;
            for(int j=0;j<n;j++)
            if(q[j]!=j && !vis[j])
            {
                vis[j]=true;
                for(int k=q[j];k!=j;k=q[k]) vis[k]=true;
                tot--;
            }
            if(tot<=m) ++tt,can[i]=true;
            for(int j=0;j<n;j++) vis[j]=q[j]=0;
        }
        printf("%d ",tt);
        for(int i=0;i<n;i++) if(can[i]) printf("%d ",i);puts("");
        for(int i=0;i<n;i++) c[i]=p[i]=can[i]=0;
    }
    return 0;
}