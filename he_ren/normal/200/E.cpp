#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

inline int exgcd(int a,int b,int &x,int &y)
{
	if(b == 0) return x = 1, y = 0, a;
	int t = exgcd(b, a%b, y, x);
	y -= a/b * x;
	return t;
}

inline int myceil(int x,int y){ return x / y + (x % y && (x > 0) == (y > 0));}
inline int myfloor(int x,int y){ return x / y - (x % y && (x > 0) != (y > 0));}

int main(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	int c3 = 0, c4 = 0, c5 = 0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		++(x == 3? c3: x == 4? c4: c5);
	}
	
	tuple<int,int,int,int> ans(inf, inf, inf, inf);
	for(int k4=0; c4*k4<=s; ++k4)
	{
		int rem = s - c4 * k4;
		int x,y,g = exgcd(c3, c5, x, y);
		if(rem % g != 0) continue;
		x *= rem/g; y *= rem/g;
		
		auto upd1 = [&] (int cx,bool lex,int &kx_l,int &kx_r,int &coefx,int &res)
		{
			if(lex)
			{
				kx_l = max(kx_l, myceil(c4 * k4, cx));
				coefx += cx;
				res -= c4 * k4;
			}
			else
			{
				kx_r = min(kx_r, myfloor(c4 * k4, cx));
				coefx += -cx;
				res += c4 * k4;
			}
		};
		
		for(int le3=0; le3<=1; ++le3)
			for(int le5=0; le5<=1; ++le5)
			{
				int res = 0;
				int k3_l = 0, k3_r = k4, coef3 = 0;
				int k5_l = k4, k5_r = rem / c5, coef5 = 0;
				upd1(c3, le3, k3_l, k3_r, coef3, res);
				upd1(c5, le5, k5_l, k5_r, coef5, res);
				
				if(k3_l > k3_r || k5_l > k5_r) continue;
				
				int kl = -inf, kr = inf;
				// l <= beg + k * t <= r
				auto upd2 = [&] (int beg,int t,int l,int r)
				{
					l -= beg; r -= beg;
					if(t < 0) l *= -1, r *= -1, t *= -1, swap(l,r);
					l = myceil(l, t);
					r = myfloor(r, t);
					kl = max(kl, l);
					kr = min(kr, r);
				};
				upd2(x, c5 / g, k3_l, k3_r);
				upd2(y, -c3 / g, k5_l, k5_r);
				
				if(kl > kr) continue;
				
				res += coef3 * x + coef5 * y;
				int coef = coef3 * (c5/g) - coef5 * (c3/g);
				
				int k = coef * kl < coef * kr? kl: kr;
				ans = min(ans, make_tuple(
					res + k * coef,
					x + k * (c5/g),
					k4,
					y - k * (c3/g)
				));
			}
	}
	if(get<0>(ans) == inf) printf("-1");
	else printf("%d %d %d",get<1>(ans),get<2>(ans),get<3>(ans));
	return 0;
}