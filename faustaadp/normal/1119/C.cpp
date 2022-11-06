#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,i,j,a[550][550],b[550][550],k;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>b[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			a[i][j]=a[i][j]^b[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				ll ki=1;
				ll ka=1;
				for(k=i+1;k<=n;k++)
					if(a[k][j]==1)
					{
						ki=k;
						break;
					}
				for(k=j+1;k<=n;k++)
					if(a[i][k]==1)
					{
						ka=k;
						break;
					}
				a[i][j]=1-a[i][j];
				a[ki][j]=1-a[ki][j];
				a[i][ka]=1-a[i][ka];
				a[ki][ka]=1-a[ki][ka];
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==1)
			{
				cout<<"No\n";
				return 0;
			}
	cout<<"Yes\n";
}