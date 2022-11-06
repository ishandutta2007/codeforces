#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n,i,a[303030],has;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]!=a[1])has=max(has,i-1);
		if(a[i]!=a[n])has=max(has,n-i);
	}
	cout<<has<<"\n";
}