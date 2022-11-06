#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll d[1010101],du,i,mo=998244353,has,n,ta;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	d[1]=1;
	du=1;
	for(i=2;i<=n;i++)
	{
		d[i]=(d[i-1]*2+du)%mo;
		du=(du*2)%mo;
		//cout<<i<<" "<<d[i]<<"\n";
	}
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		has=((ta*d[n-i+1])%mo+has)%mo;
	}
	cout<<has<<"\n";
}