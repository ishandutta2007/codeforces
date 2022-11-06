#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,x[1010],has;
pair<ll,ll> A[1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		A[i]=mp(-ta,i);
	}
	sort(A+1,A+1+n);
	for(i=1;i<=n;i++)
	{
		has-=A[i].fi*(i-1);
		x[i]=A[i].se;
	}
	has+=n;
	cout<<has<<"\n";
	for(i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<"\n";
}