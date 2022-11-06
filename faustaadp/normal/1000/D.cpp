#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,C[1010][1010],a[1010],mo=998244353,has,d[1010],p[1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	C[0][0]=1;
	for(i=1;i<=1000;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=mo;
		}
	}
	
//	return 0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=n;i>=1;i--)
	{
		if(a[i]>0&&a[i]<=1001)
		{
			d[i]=C[n-i][a[i]];
			for(j=i+1;j<n;j++)
			{
				d[i]+=C[j-i-1][a[i]-1]*p[j+1];
				d[i]%=mo;
			}
			has+=d[i];
			has%=mo;
		//	cout<<i<<" "<<d[i]<<"\n";
		}
		p[i]=p[i+1]+d[i];
		p[i]%=mo;
	}
	cout<<has<<"\n";
	
}