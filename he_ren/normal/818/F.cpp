#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
typedef long double db;
using namespace std;

ll n;
inline bool chk(ll mid)
{
	ll t = (mid>>1ll) + (mid&1ll);
	ll m=n-t;
	mid-=t;
	
	if(m<=0) return 0;
	return (db)m-1 >= (db)(mid<<1ll)/m;
}

void solve(void)
{
	cin>>n;
	
	ll l=0, r = (n&1ll)? ((n-1)>>1ll)*n: (n>>1ll)*(n-1);
	while(l<r)
	{
		ll mid = (l>>1ll) + (r>>1ll) + (((l&1ll)+(r&1ll)+1)>>1ll);
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}