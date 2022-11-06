#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5
#define K 1000000000
#define M 1000000000000000000LL

int n, s[N];

struct Rectangle
{
	int x, y;
	LL a;
	void read()
	{
		scanf("%d%d%lld", &x, &y, &a);
	}
	bool operator < (const Rectangle& obj) const
	{
		return x < obj.x;
	}
}Rec[N];

struct Int128
{
	LL a, b;
	Int128 () {}
	Int128 (LL x) : Int128(0, x) {}
	Int128 (LL a, LL b) : a(a), b(b) {}
	Int128 operator + (Int128 obj)
	{
		Int128 res(a + obj.a, b + obj.b);
		if (res.b >= M)
			res.b -= M, res.a ++;
		return res;
	}
	Int128 operator + (LL x)
	{
		return *this + Int128(x);
	}
	Int128 operator - (Int128 obj)
	{
		Int128 res(a - obj.a, b - obj.b);
		if (res.b < 0)
			res.b += M, res.a --;
		return res;
	}
	Int128 operator - (LL x)
	{
		return *this - Int128(x);
	}
	Int128 operator * (int x)
	{
		int a1 = a / K, a2 = a % K;
		int b1 = b / K, b2 = b % K;
		int _b2 = 1LL * b2 * x % K;
		int _b1 = (1LL * b1 * x + 1LL * b2 * x / K) % K;
		int _a2 = (1LL * a2 * x + (1LL * b1 * x + 1LL * b2 * x / K) / K) % K;
		int _a1 = (1LL * a1 * x + (1LL * a2 * x + (1LL * b1 * x + 1LL * b2 * x / K) / K) / K) % K;
		return Int128(1LL * _a1 * K + _a2, 1LL * _b1 * K + _b2);
	}
	bool operator < (const Int128& obj) const
	{
		return make_pair(a, b) < make_pair(obj.a, obj.b);
	}
	void out()
	{
		if (!a)
			printf("%lld\n", b);
		else printf("%lld%018lld\n", a, b);
	}
}Max, Dp[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		Rec[i].read();
	sort(Rec + 1, Rec + n + 1);
	int head = 0, tail = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (; head < tail && !((Dp[s[head + 1]] - Dp[s[head]]) < Int128(1LL * (Rec[s[head + 1]].x - Rec[s[head]].x) * Rec[i].y)); head ++) ;
		Dp[i] = Dp[s[head]] + 1LL * Rec[i].x * Rec[i].y - Rec[i].a - 1LL * Rec[s[head]].x * Rec[i].y;
		Max = Max < Dp[i] ? Dp[i] : Max;
		for (; head < tail && !((Dp[i] - Dp[s[tail]]) * (Rec[i].x - Rec[s[tail - 1]].x) < (Dp[i] - Dp[s[tail - 1]]) * (Rec[i].x - Rec[s[tail]].x)); tail --) ;
		s[++ tail] = i;
	}
	Max.out();
	return 0;
}