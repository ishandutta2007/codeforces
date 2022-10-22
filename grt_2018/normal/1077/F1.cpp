#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 202;
const long long INF = (long long)1000*1000*1000*1000*1000*1000;

int k,n,x;
int T[MAXN];
long long DP[MAXN][MAXN];

int main()
{
    cin>>n>>k>>x;
    for(int i=1; i<=n;i++)
        cin>>T[i];
    for(int i=0; i<=n+1;i++)
        for(int j=0; j<=x+1;j++)
            DP[i][j]=-INF;
    DP[0][x]=0;
    for(int i=1; i<=n;i++)
    {
        for(int j=0; j<x;j++)
        {
            for(int z=1; z<=k;z++)
            {
                if(i-z<0) break;
                if(DP[i-z][j+1]==-INF) continue;
                DP[i][j]=max(DP[i][j],DP[i-z][j+1]+T[i]);
            }
        }
    }
    long long w=-INF;
    for(int i = n - k + 1; i <= n; ++i)
    {
        for(int j=0; j<x;j++)
            w=max(w,DP[i][j]);
    }
    if(w==-INF) cout<<"-1";
    else cout<<w;
    return 0;
}