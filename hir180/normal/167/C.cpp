#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ok(ll x,ll y)
{
	if(x>y) swap(x,y);
	if(x==0) return 0;
	if(!ok(x,y%x)) return 1;
	ll d = (y/x);
	return ((d%(x+1LL))%2+100)%2==0;
}
int main()
{
	int n; cin >> n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin >> x >> y;
		puts(ok(x,y)?"First":"Second");
	}
}