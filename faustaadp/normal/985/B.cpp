#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
ll n,m,i,j,d[2020],bisa;
char a[2020][2020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
				d[j]++;
		}
	for(i=1;i<=n;i++)
	{
		bisa=1;
		for(j=1;j<=m;j++)
			if(a[i][j]=='1'&&d[j]==1)
				bisa=0;
		if(bisa)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	
}