#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
ll n,d,i,a[101010],x[101010],y[101010],k,j,dis[1010][1010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>d;
    for(i=2;i<n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dis[i][j]=max(0LL,(abs(x[i]-x[j])+abs(y[i]-y[j]))*d-a[j]);
  //  cout<<dis[1][n]<<"\n";
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    cout<<dis[1][n]<<"\n";

}