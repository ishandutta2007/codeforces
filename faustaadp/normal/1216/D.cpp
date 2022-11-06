#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],ma,y,z;
ll fpb(ll aa,ll bb)
{
	if(bb==0)
		return aa;
	else
		return fpb(bb,aa%bb);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
		z=fpb(z,a[i+1]-a[i]);
	for(i=1;i<=n;i++)
		y+=ma-a[i];
	y/=z;
	cout<<y<<" "<<z<<"\n";
}