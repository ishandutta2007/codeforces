#include <cstdio>
typedef long long LL;

LL m, res, a_1, b_1, a_2, b_2, l, r, d, ans;

inline LL Abs(LL x)
{
	return x > 0 ? x : -x;
}

inline LL gcd(LL x, LL y)
{
	return !y ? x : gcd(y, x % y);
}

inline LL Phi(LL x)
{
	LL p = 1, _x = x;
	for (int i = 2; i * i <= x; i ++)
		if (_x % i == 0)
		{
			_x /= i, p *= (i - 1);
			for (; _x % i == 0; _x /= i) p *= i;
		}
	if (_x > 1) p *= (_x - 1);
	return p;
}

inline LL Inc(LL a, LL b, LL Mod)
{
	return a + b - (a + b >= Mod ? Mod : 0);
}

inline LL Multi(LL x, LL y, LL Mod)
{
	LL p = 0;
	for (x %= Mod, y %= Mod; y; y >>= 1)
	{
		if (y & 1) p = Inc(p, x, Mod);
		x = Inc(x, x, Mod);
	}
	return p;
}

inline LL Power(LL x, LL y, LL Mod)
{
	LL p = 1 % Mod;
	for (; y; y >>= 1)
	{
		if (y & 1) p = Multi(p, x, Mod);
		x = Multi(x, x, Mod);
	}
	return p;
}

inline LL Div(LL x, LL k)
{
	if (x >= 0) return x / k;
	return (x - k + 1) / k;
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a_1, &b_1, &a_2, &b_2, &l, &r);
	if (b_1 > b_2)
	{
		a_1 += a_2, a_2 = a_1 - a_2, a_1 -= a_2;
		b_1 += b_2, b_2 = b_1 - b_2, b_1 -= b_2;
	}
	b_2 -= b_1, l -= b_1, r -= b_1;
	d = gcd(a_1, a_2);
	if (b_2 % d) puts("0");
	else if (l > r)
	{
		puts("0");
		//puts("What the fuck?");
	}
	else
	{
		a_1 /= d, a_2 /= d, b_2 /= d;
		if (l >= 0) l = (l + d - 1) / d;
			else l = l / d;
		if (r >= 0) r = r / d;
			else r = (r - d + 1) / d;
		m = a_1 * a_2;
		res = Multi(Power(a_1, Phi(a_2), m), b_2, m);
		LL _k = res / a_1, _l = (res - b_2) / a_2;
		if (_l < 0)
		{
			LL t = Abs(Div(_l, a_1));
			res += t * m;
		}
		LL ans_1 = 0, ans_2 = 0;
		if (r < res) ans_1 = 0;
			else ans_1 = (r - res) / m + 1;
		if (l <= res) ans_2 = 0;
			else ans_2 = (l - 1 - res) / m + 1;
		ans = ans_1 - ans_2;
		printf("%I64d\n", ans);
	}
	return 0;
}