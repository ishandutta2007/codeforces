#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,r,hz,i,ta;
bool b[303030];
vector<ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	cout<<1;
	r=n;
	hz=2;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		b[ta]=1;
		while(ta==r&&b[ta]==1)
		{
			hz--;
			ta--;
			r--;
		}
		cout<<" "<<hz;
		hz++;
	}
	cout<<"\n";
}