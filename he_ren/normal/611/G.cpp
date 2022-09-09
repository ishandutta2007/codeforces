#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll inv2 = (mod+1)/2;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b>=mod? a+b-mod: a+b;}
inline int reg_mod(ll x){ return (x%=mod) < 0? x+mod: x;}

struct Vector
{
	int x,y;
	Vector(void){}
	Vector(int _x,int _y): x(_x), y(_y) {}
};
inline ll cross(const Vector &p,const Vector &q){ return (ll)p.x * q.y - (ll)p.y * q.x;}

Vector p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	
	for(int i=1; i<=n; ++i) p[i+n] = p[i];
	p[2*n+1] = p[1];
	
	static int sumf[MAXN], sumg[MAXN], sumx[MAXN], sumy[MAXN];
	for(int i=1; i<=2*n; ++i)
	{
		int cur = reg_mod(cross(p[i+1], p[i]));
		sumf[i] = mod_add(sumf[i-1], cur);
		sumg[i] = mod_add(sumg[i-1], (ll)cur * i %mod);
		sumx[i] = mod_add(sumx[i-1], reg_mod(p[i].x));
		sumy[i] = mod_add(sumy[i-1], reg_mod(p[i].y));
	}
	
	ll totarea = 0;
	for(int i=1; i<=n; ++i) totarea += cross(p[i+1], p[i]);
	
	ll curarea = 0, ans = 0;
	for(int l=1,r=1; l<=n; ++l)
	{
		while(curarea + cross(p[l], p[r]) <= totarea / 2)
			curarea += cross(p[r+1], p[r]), ++r;
		// [l+2, r-1], [r, l+n-2]
		
		auto getres = [&] (int tl,int tr) -> ll
		{
			if(tl > tr) return 0;
			ll res = 0;
			res = (res + (ll)p[l].x * (sumy[tr] - sumy[tl-1])) %mod;
			res = (res - (ll)p[l].y * (sumx[tr] - sumx[tl-1])) %mod;
			res = (res + (ll)(sumf[tl-1] - sumf[l-1]) * (tr-tl+1)) %mod;
			res = (res - (ll)(sumg[tr] - sumg[tl-1])) %mod;
			res = (res + (ll)(sumf[tr] - sumf[tl-1]) * tr) %mod;
			return reg_mod(res);
		};
		
		if(l+2 <= r-1)
		{
			ans += getres(l+2, r-1);
		}
		if(r <= l+n-2)
		{
			ans += (ll)reg_mod(totarea) * (l+n-2 - r + 1) %mod - getres(r, l+n-2);
		}
		
		ans = reg_mod(ans);
		curarea -= cross(p[l+1], p[l]);
	}
	
	ans = ((ll)reg_mod(totarea) * n %mod * (n-3) %mod - 2 * ans) %mod;
	ans = ans * inv2 %mod;
	ans = reg_mod(ans);
	printf("%lld",ans);
	return 0;
}