#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[110],h1,h2;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	n/=2;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
		h1+=abs(a[i]-(i*2-1));
	for(i=1;i<=n;i++)
		h2+=abs(a[i]-(i*2));
	cout<<min(h1,h2)<<"\n";
}