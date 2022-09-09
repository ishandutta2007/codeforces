#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

inline ll calc1(ll P)
{
	return pw((1-P) %mod, mod - 2);
}
inline ll calc2(ll P)
{
	ll t = pw((1-P) %mod, mod - 2);
	return P * t %mod * t %mod;
}
inline ll calc3(ll A,ll B,ll P,ll Q)
{
	return (A * calc2(P) + B * calc1(P)) %mod * Q %mod;
}

void solve(void)
{
	int n,m,sx,sy,tx,ty,p;
	scanf("%d%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty,&p);
	p = p * pw(100, mod-2) %mod;
	
	int len = (n - 1) * 2 * (m - 1) * 2;
	vector<int> has;
	for(int i=0, x=sx, y=sy, dx=1, dy=1; i<len; ++i)
	{
		if(x == tx || y == ty) has.push_back(i);
		if(x + dx > n || x + dx < 1) dx = -dx;
		if(y + dy > m || y + dy < 1) dy = -dy;
		x += dx; y += dy;
	}
	int tot = (int)has.size();
	
	int ans = 0;
	for(int i=0; i<(int)has.size(); ++i)
	{
		ll f = pw((1-p)%mod, tot) %mod;
		ll g = pw((1-p)%mod, i) * p %mod;
		ans = (ans + calc3(len, has[i], f, g)) %mod;
	}
	ans = (ans %mod + mod) %mod;
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}