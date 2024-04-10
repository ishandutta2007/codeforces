#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,j,ganjil,K;
char a[1010][1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=4;i++)
		for(j=1;j<=n;j++)
			a[i][j]='.';
	if(k%2==1)
		ganjil=1;
	K=k/2;
	for(i=2;i<=n/2;i++)
	{
		for(j=2;j<=3;j++)
		{
			if(K>0)
			{
				K--;
				a[j][i]='#';
			}
		}
	}
	K=k/2;
	for(i=n-1;i>n/2+1;i--)
	{
		for(j=2;j<=3;j++)
		{
			if(K>0)
			{
				K--;
				a[j][i]='#';
			}
		}
	}
	if(k==(n-2)*2)
	{
		a[2][n/2+1]='#';
		a[3][n/2+1]='#';
	}
	if(ganjil)
		a[2][n/2+1]='#';
	cout<<"YES\n";
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=n;j++)
			cout<<a[i][j];
		cout<<"\n";
	}
}