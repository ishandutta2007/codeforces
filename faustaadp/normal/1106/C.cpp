#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,nn,a[303030],has;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	nn=n/2;
	for(i=1;i<=nn;i++)
		has+=(a[i]+a[n-i+1])*(a[i]+(a[n-i+1]));
	cout<<has<<"\n";
}