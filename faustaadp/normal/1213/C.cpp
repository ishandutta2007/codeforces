#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,m,i,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll z=n/m;
		ll y=z%10;
		z/=10;
		has=0;
		for(i=0;i<10;i++)
			has+=z*((i*m)%10);
		for(i=0;i<=y;i++)
			has+=((i*m)%10);
		cout<<has<<"\n";
	}
}