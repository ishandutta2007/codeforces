#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,dp[101][101][2],ans;
pair<int,int> a[101];
int main()
{
    cin>>n;
    a[0].first=-1e9;
    for(int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    for(int i=0;i<n;++i)
        for(int j=0;j<=i;++j)
            for(int k=0;k<2;++k)
            {
                int l=a[j].first+k*a[j].second,r,maxn=-1e9,x,y;
                for(int p=i+1;p<=n;++p)
                    for(int q=0;q<2;++q)
                    {
                        int r=a[p].first+q*a[p].second;
                        if(r>maxn)
                        {
                            maxn=r;
                            x=p;
                            y=q;
                        }
                        dp[p][x][y]=max(dp[p][x][y],dp[i][j][k]+maxn-r+min(a[p].second,r-l));
                    }
            }
    for(int i=1;i<=n;++i)
        ans=max({ans,dp[n][i][0],dp[n][i][1]});
    cout<<ans<<'\n';
    return 0;
}