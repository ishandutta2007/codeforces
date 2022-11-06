#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,a[101010],b[101010],p1[101010],p0[101010],has;	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=1;i<=n;i++)
	{
		p1[i]=p1[i-1];
		p0[i]=p0[i-1];
		if(b[i])
			p1[i]+=a[i];
		else
			p0[i]+=a[i];
	}
	for(i=1;i<=n-k+1;i++)
	{
		has=max(has,p1[n]+(p0[i+k-1]-p0[i-1]));
	}
	cout<<has<<"\n";
}