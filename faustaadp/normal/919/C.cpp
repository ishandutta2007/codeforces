#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,k,i,j,hz,hs;
char a[2020][2020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
//	n=2000;
//	m=2000;
//	k=2;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	//		a[i][j]='.';
	for(i=1;i<=n;i++)
	{
		hz=0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
				hz++;
			else
				hz=0;
			if(hz>=k)
				hs++;
		}
	}
	if(k==1)
	{
		cout<<hs<<"\n";
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		hz=0;
		for(j=1;j<=n;j++)
		{
			if(a[j][i]=='.')
				hz++;
			else
				hz=0;
			if(hz>=k)
				hs++;
		}
	}
	cout<<hs<<"\n";
}