#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;

inline ll encode(int x,int y){ return (ll)x * n + y;}
inline void decode(ll u,int &x,int &y){ x = u / n; y = u % n;}

inline int dist(ll u,ll v)
{
	return abs(u / n - v / n) + abs(u % n - v % n);
}

inline ll calc(ll s,ll t,ll q)
{
	return (ll)(dist(s, q) + dist(t, q)) * (dist(s, t) + 1) / 2 - dist(s, q);
}

int xl, yl, xr, yr;
ll p1, p2, p3, p4;// LD, LU, RD, RU

inline bool chk(ll u,ll T1,ll T2,ll T3,ll T4)
{
	int x,y; decode(u,x,y);
	bool flag = T1 >= 0 && T2 >= 0 && T3 >= 0 && T4 >= 0;
	auto walk = [&] (int tx,int ty)
	{
		assert(tx == x || ty == y);
		ll v = encode(tx, ty);
		T1 -= calc(u, v, p1); T2 -= calc(u, v, p2);
		T3 -= calc(u, v, p3); T4 -= calc(u, v, p4);
		u = v; x = tx; y = ty;
		flag &= T1 >= 0 && T2 >= 0 && T3 >= 0 && T4 >= 0;
	};
	
	if(x < xl) walk(xl, y);
	if(y < yl) walk(x, yl);
	
	ll saveu = u;
	bool has_inside = 0;
	if(x <= xr && y <= yr)
	{
		has_inside = 1;
		saveu = u;
		x = xr; y = yr; u = p4;
	}
	assert(x >= xr || y >= yr);
	
	if(x < xr) walk(xr, y);
	if(y < yr) walk(x, yr);
	assert(x >= xr && y >= yr);
	
	walk(n-1, y);
	walk(x, n-1);
	
	if(has_inside)
	{
		u = saveu; decode(u, x, y);
		if(!flag) return 0;
		
		ll t2 = encode(x, yr), t3 = encode(xr, y);
		auto inside = [&] (ll mid,ll q)
		{
			return calc(u, mid, q) + calc(mid, p4, q);
		};
		
		T1 -= inside(t2, p1); T4 -= inside(t2, p4);
		if(T1 < 0 || T4 < 0) return 0;
		
		ll mn2 = inside(t2, p2), mx2 = inside(t3, p2);
		ll mn3 = inside(t3, p3), mx3 = inside(t2, p3);
		assert(mn2 + mx3 == mn3 + mx2);
		assert(mn2 % 2 == mx2 % 2);
		assert(mn3 % 2 == mx3 % 2);
		ll tot = mn2 + mx3;
		
		if(T2 + T3 < tot) return 0;
		if(T2 < mn2 || T3 < mn3) return 0;
		ll use2 = min(mx2, T2 - (T2 - mn2) % 2);
		if(T3 < tot - use2) return 0;
	}
	
	return flag;
}

int main(void)
{
	ll T;
	int c;
	scanf("%d%lld%d%d%d",&n,&T,&xl,&yl,&c);
	--xl; --yl; xr = xl + c - 1; yr = yl + c - 1;
	
	p1 = encode(xl, yl); p2 = encode(xl, yr);
	p3 = encode(xr, yl); p4 = encode(xr, yr);
	
	ll T1, T2, T3, T4;
	T1 = T2 = T3 = T4 = T;
	if(!chk(encode(0, 0), T1, T2, T3, T4))
	{
		printf("Impossible");
		return 0;
	}
	
	int x = 0, y = 0;
	string ans;
	while(x < n-1 || y < n-1)
	{
		auto try_walk = [&] (int xx,int yy)
		{
			if(xx >= n || yy >= n) return false;
			ll v = encode(xx, yy);
			return chk(v, T1 - dist(v, p1), T2 - dist(v, p2), T3 - dist(v, p3), T4 - dist(v, p4));
		};
		
		if(try_walk(x+1, y)) ++x, ans += 'R';
		else ++y, ans += 'U';
		
		ll v = encode(x, y);
		T1 -= dist(v, p1); T2 -= dist(v, p2);
		T3 -= dist(v, p3); T4 -= dist(v, p4);
		assert(T1 >= 0 && T2 >= 0 && T3 >= 0 && T4 >= 0);
	}
	
	cout << ans;
	return 0;
}