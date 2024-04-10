#include<iostream>
#include<cstdio>
using namespace std;
int n;
double p[1001][1001],val[1001],dis[1001];
bool vis[1001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%lf",&p[i][j]);
            p[i][j]/=100;
        }
    for(int i=1;i<n;++i)
    {
        dis[i]=1.0000;
        val[i]=1.0000-p[i][n];
    }
    vis[n]=1;
    for(int i=1;i<n;++i)
    {
        double minn=1e18;
        int node=0;
        for(int j=1;j<=n;++j)
            if(!vis[j]&&dis[j]/(1-val[j])<minn)
            {
                minn=dis[j]/(1-val[j]);
                node=j;
            }
        vis[node]=1;
        for(int j=1;j<=n;++j)
            if(!vis[j])
            {
                dis[j]+=dis[node]/(1-val[node])*val[j]*p[j][node];
                val[j]*=1-p[j][node];
            }
    }
    printf("%.10lf\n",dis[1]/(1-val[1]));
    return 0;
}