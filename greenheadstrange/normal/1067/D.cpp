#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define maxn 100005
#define ll long long
#define ld double
using namespace std;
int a[maxn], b[maxn];
ld p[maxn];
struct point
{
	ld x, y;
	bool operator < (const point &a)const
	{
		if(y != a.y) return y > a.y;
		return x > a.x;
	}
}nd[maxn];
ld k(point a, point b)
{
	return (b.y - a.y) / (b.x - a.x);
}
point stack[maxn];
int top;
ld ksm(ld a, ll k)
{
	if(k == 0) return 1;
	ld ns = ksm(a, k >> 1);
	ns = ns * ns;
	if(k & 1) ns = ns * a;
	return ns;
}
ld cal1(ld p, ld ms, ld k)
{
	// k0
	ld ans = k * (1 - ksm(p, ms + 1)) / (1 - p);
//	cout<<p<<" "<<ms<<" "<<k<<" "<<ans<<endl;
	return ans;
}
ld cal2(ld p, ld ms, ld k)
{
	//kx
	ld ans = k * (cal1(p, ms, 1) - ms * ksm(p, ms + 1) - 1) / (1 - p);
//	cout<<p<<" "<<ms<<" "<<k<<" "<<ans<<endl;
	return ans;
}
ld mv(ll fr, ll ed, ld k, ld b, ld p, ld frs)
{
	//cout<<"MV"<<fr<<" "<<ed<<" "<<k<<" "<<b<<" "<<p<<" "<<frs<<endl;
	if(fr == ed) return frs;
	ld n1 = ksm(p, ed - fr) * frs;
	ld n2 = cal1(p, ed - 1 - fr, k * (ed - 1) + b) + cal2(p, ed - 1 - fr, -k);
//	cout<<n2<<endl;
	return n1 + n2;
}
int main()
{
	ld s = 0;
	int n;
	ll t;
	scanf("%d%lld", &n, &t);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%lf", &a[i], &b[i], &p[i]);
		s = max(s, b[i] * p[i]);
		nd[i].x = p[i], nd[i].y = a[i] * p[i];
	}
	sort(nd + 1, nd + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(nd[i].y == stack[top - 1].y) continue;
		if(i && nd[i].x < stack[top - 1].x) continue;
		while(top >= 2 && k(stack[top - 1], nd[i]) >= k(stack[top - 2], stack[top - 1])) top--;
		stack[top++] = nd[i];
	}
//	cout<<top<<endl;
	ll nt = 0;
	ld lans = 0;
	for(int i = 0; i < top; i++)
	{
		if(nt == t) break;
		ld nk = stack[i].x * s, nb = stack[i].y, np = (1 - stack[i].x);
//		cout<<nk<<" "<<nb<<" "<<np<<" "<<s<<endl;
		ll l = nt, r = t;
		if(i == top - 1)
			l = t;
		while(l < r)
		{
			ll mid = (l + r) >> 1;
			ld nans = mv(nt, mid, nk, nb, np, lans);
			if(-k(stack[i], stack[i + 1]) <= mid * s - nans)
				r = mid;
			else l = mid + 1;
		}
		lans = mv(nt, l, nk, nb, np, lans);
		nt = l;
	}
//	cout<<lans<<endl;
	printf("%.10lf\n", lans);
	return 0;
}