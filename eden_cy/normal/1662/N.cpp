#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n;

int a[N][N],cx[N],cy[N];

pair<int,int>pos[N*N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]),pos[a[i][j]]=make_pair(i,j);
    long long ans=0;
    for(int i=1;i<=n*n;i++)
    {
        int x=pos[i].first,y=pos[i].second;
        ans+=cx[x]*(n-1-cy[y])+cy[y]*(n-1-cx[x]);
        cx[x]++,cy[y]++;
    }
    printf("%lld\n",ans>>1);
}