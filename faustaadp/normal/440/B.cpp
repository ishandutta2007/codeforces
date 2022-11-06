#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[101010],has,jum;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		jum+=a[i];
	}
	jum/=n;
	for(i=1;i<n;i++)
	{
		a[i]-=jum;
		has+=abs(a[i]);
		a[i+1]+=a[i];
	}
	cout<<has<<"\n";
}