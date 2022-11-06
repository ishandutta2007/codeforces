#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,P,Q,R,i,a[101010],p[101010],s[101010],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>P>>Q>>R;
	for(i=1;i<=n;i++)
		cin>>a[i];
	p[0]=-4e18;
	s[n+1]=-4e18;
	has=-4e18;
	for(i=1;i<=n;i++)
		p[i]=max(p[i-1],a[i]*P);
	for(i=n;i>=1;i--)
		s[i]=max(s[i+1],a[i]*R);
	for(i=1;i<=n;i++)
		has=max(has,a[i]*Q+p[i]+s[i]);
	cout<<has<<"\n";
}