#include <cstdio>
typedef long long LL;
#define eps 1e-6

int n, w, v, u, x, y;

struct Frac
{
	LL fz, fm;
	LL gcd(LL x, LL y)
	{
		return !y ? x : gcd(y, x % y);
	}
	LL Abs(LL x)
	{
		return x > 0 ? x : -x;
	}
	void Simplify()
	{
		if (fm < 0) fz = -fz, fm = -fm;
		LL d = gcd(Abs(fz), Abs(fm));
		fz /= d, fm /= d;
	}
	Frac (LL _fz = 0, LL _fm = 1) {fz = _fz, fm = _fm; Simplify();}
	bool operator < (Frac a)
	{
		return fz * a.fm < fm * a.fz;
	}
	bool operator <= (Frac a)
	{
		return fz * a.fm <= fm * a.fz;
	}
	bool operator > (Frac a)
	{
		return fz * a.fm > fm * a.fz;
	}
	bool operator >= (Frac a)
	{
		return fz * a.fm >= fm * a.fz;
	}
	Frac operator + (Frac a)
	{
		Frac b;
		b.fz = fz * a.fm + fm * a.fz;
		b.fm = fm * a.fm;
		b.Simplify();
		return b;
	}
	Frac operator - (Frac a)
	{
		Frac b;
		b.fz = fz * a.fm - fm * a.fz;
		b.fm = fm * a.fm;
		b.Simplify();
		return b;
	}
	Frac operator * (Frac a)
	{
		Frac b;
		b.fz = fz * a.fz;
		b.fm = fm * a.fm;
		b.Simplify();
		return b;
	}
	Frac operator / (Frac a)
	{
		Frac b;
		b.fz = fz * a.fm;
		b.fm = fm * a.fz;
		b.Simplify();
		return b;
	}
	void out(int k)
	{
		if (fz < 0) putchar('-');
		LL _fz = Abs(fz);
		printf("%I64d.", _fz / fm);
		for (int i = 1; i <= k; i ++)
		{
			_fz %= fm;
			_fz *= 10;
			printf("%I64d", _fz / fm);
		}
		puts("");
	}
}Min, Max, Zero, ans;

int main()
{
	scanf("%d%d%d%d", &n, &w, &v, &u);
	scanf("%d%d", &x, &y);
	Min = Max = Frac(x, 1) - Frac((LL) y * v, u);
	for (int i = 2; i <= n; i ++)
	{
		scanf("%d%d", &x, &y);
		Frac tmp = Frac(x, 1) - Frac((LL) y * v, u);
		Min = Min < tmp ? Min : tmp;
		Max = Max > tmp ? Max : tmp;
	}
	Zero = Frac(0, 1);
	if (Min >= Zero || Max <= Zero) Max = Zero;
	ans = Max / Frac(v, 1) + Frac(w, u);
	ans.out(7);
	return 0;
}