#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll has,n,m,i,j,a[1010][1010],ta,mo=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	has=1;
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		for(j=1;j<=ta;j++)
			a[i][j]=1;
		a[i][ta+1]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>ta;
		for(j=1;j<=ta;j++)
		{
			if(a[j][i]==0)
			{
				// cout<<j<<" "<<i<<"__\n";
				// cout<<a[j][i]<<"____\n";
				has=0;
			}
			a[j][i]=1;
		}
		if(a[ta+1][i]==1)
			has=0;
		a[ta+1][i]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			// cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
			if(a[i][j]==-1)
				has=(has*2LL)%mo;
		}
	cout<<has<<"\n";
}