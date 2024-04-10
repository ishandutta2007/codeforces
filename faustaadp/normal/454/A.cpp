#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j;
bool b[1010][1010];
void blok(ll aa,ll bb,ll cc)
{
	ll ii;
	for(ii=bb;ii<=cc;ii++)
		b[aa][ii]=1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n/2;i++)
		blok(i,n/2-i+2,n/2+i);
	blok(n/2+1,1,n);
	for(i=n;i>=n/2+2;i--)
	{
		j++;
		blok(i,n/2-j+2,n/2+j);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(b[i][j])
				cout<<'D';
			else
				cout<<'*';
		cout<<"\n";
	}
}