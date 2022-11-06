#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,m,h,a[110],b[110],c[110][110],i,j;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>h;
	for(i=1;i<=m;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]!=0)
				c[i][j]=min(a[j],b[i]);
			if(j==m)cout<<c[i][j]<<"\n";
			else cout<<c[i][j]<<" ";
		}
}