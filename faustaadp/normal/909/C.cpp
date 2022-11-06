#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,d[2][5050],mo=1000000007,j,p[2][5050];
char a[5050];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		d[n%2][i]=1;
		p[n%2][i]=i;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]=='f')
				d[i%2][j]=d[1-i%2][j+1]%mo;
			else
				d[i%2][j]=p[1-i%2][j]%mo;
		}
		for(j=1;j<=n;j++)
		{
			p[i%2][j]=p[i%2][j-1]+d[i%2][j];
			p[i%2][j]%=mo;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<d[i][j]<<" ";
		cout<<"\n";
	}*/
	cout<<d[1][1]%mo<<"\n";
}