#include<bits/stdc++.h>
using namespace std;
const int maxn=666;
const int inf=1000000666;
int d[maxn],dis[maxn],a[maxn][maxn],n,m;
bool vis[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]=inf;
    while (m--){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        a[u][v]=w;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) d[j]=inf;
        d[i]=0;
        memset(vis,0,sizeof(vis));
        for (int r=1;r<n;r++){
            int p=-1;
            for (int j=0;j<n;j++) if (!vis[j]){
                if (p==-1||d[j]<d[p]) p=j;
            }
            for (int j=0;j<n;j++) dis[(j+d[p])%n]=d[p]+a[p][j];
            for (int j=1;j<n;j++) dis[j]=min(dis[j],dis[j-1]+1); dis[0]=min(dis[0],dis[n-1]+1);
            for (int j=1;j<n;j++) dis[j]=min(dis[j],dis[j-1]+1);
            for (int j=0;j<n;j++) d[j]=min(d[j],dis[j]);
            vis[p]=1;
        }
        for (int j=0;j<n;j++) printf("%d ",d[j]);puts("");
    }
    return 0;
}