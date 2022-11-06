#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,jum,a[202020],g1[2][202020],g2[2][202020],has,h1,h2;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)jum+=a[i];
	for(i=1;i<=n;i++)g1[0][i]=g1[0][i-1]+(i%2==0)*a[i];
	for(i=1;i<=n;i++)g1[1][i]=g1[1][i-1]+(i%2==1)*a[i];
	for(i=n;i>=1;i--)g2[0][i]=g2[0][i+1]+(i%2==0)*a[i];
	for(i=n;i>=1;i--)g2[1][i]=g2[1][i+1]+(i%2==1)*a[i];
	for(i=1;i<=n;i++)
	{
		h1=g1[0][i-1]+g2[1][i+1];
		h2=g1[1][i-1]+g2[0][i+1];
		if(h1==h2)has++;
	}
	cout<<has<<"\n";
}