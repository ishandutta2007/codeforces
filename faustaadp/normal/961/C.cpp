#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,k,A[10],has;
char a[5][110][110];
ll oi(ll aa,ll bb)
{
	ll ii,jj,ha=0;
	for(ii=1;ii<=n;ii++)
	{
		for(jj=1;jj<=n;jj++)
		{
			if((ii+jj+bb)%2!=a[aa][ii][jj]-'0')
				ha++;
		}
	}
	return ha;
}
void hem(ll aa)
{
	if(aa==4)
	{
		if(A[1]+A[2]+A[3]+A[4]==2)
		{
			ll he=0,ii;
			for(ii=1;ii<=4;ii++)
			{
			//	cout<<A[ii]<<" ";
				he+=oi(ii,A[ii]);
			}
			//cout<<he<<"\n";
			has=min(has,he);
		}
		else
			return ;
	}
	else
	{
		A[aa+1]=1;
		hem(aa+1);
		A[aa+1]=0;
		hem(aa+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				cin>>a[i][j][k];
		}
	}
	has=1e18;
	hem(0);
	cout<<has<<"\n";
}