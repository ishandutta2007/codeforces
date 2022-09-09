#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n,h;

inline bool chk(ll lim)
{
	if(lim <= h)
		return lim + 1 >= (n * 2 + lim - 1) / lim;
	
	ll t = n;
	if(lim - h >= (t + h - 1) / h) return 1;
	t -= (lim - h) * h;
	
	if(h + 1 >= (t * 2 + h - 1) / h) return 1;
	t -= h * (h+1) / 2;
	
	ll len = lim - h - 1;
	if(len <= 1) return t <= len;
	
	ll half = len / 2;
	if(half + 1 >= (t + half - 1) / half) return 1;
	t -= half * (half + 1);
	
	if(len&1) return t <= (len + 1) / 2;
	else return !t;
}

int main(void)
{
	scanf("%lld%lld",&n,&h);
	
	ll l = 1, r = n;
	while(l < r)
	{
		ll mid = (l+r)>>1;
		if(chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld",l);
	return 0;
}