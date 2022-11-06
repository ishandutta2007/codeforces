#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define K 512
#define Mod 998244353

int n, m, Last[N], Left[N], Dp[N], Val[N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

class Block
{
public:
	Block() { flag = false; }
	void init(int _l, int _r)
	{
		if (flag)
		{
			fprintf(stderr, "Warning : This Block was initialized with (%d, %d)\n", l, r);
			return;
		}
		l = _l, r = _r, Min = Max = del = 0;
		flag = true;
	}
	bool CheckInit(const char *description) const
	{
		if (!flag)
		{
			fprintf(stderr, "%s : This Block wasn't initialized\n", description);
			return false;
		}
		return true;
	}
	void Rebuild()
	{
		if (!CheckInit("Rebuild")) return;
		for (int i = l; i <= r; i ++)
			Val[i] += del;
		for (int i = Min; i <= Max; i ++)
			Sum[i] = 0;
		del = 0, Max = Min = Val[l];
		for (int i = l; i <= r; i ++)
		{
			Min = min(Min, Val[i]);
			Max = max(Max, Val[i]);
			Sum[Val[i]] = Inc(Sum[Val[i]], Dp[i - 1]);
		}
		for (int i = Min + 1; i <= Max; i ++)
			Sum[i] = Inc(Sum[i], Sum[i - 1]);
	}
	void Add(int _l, int _r, int k)
	{
		if (!CheckInit("Add")) return;
		_l = max(l, _l), _r = min(r, _r);
		if (_l > _r) return ;
		else if (_l == l && _r == r)
			del += k;
		else
		{
			for (int i = _l; i <= _r; i ++)
				Val[i] += k;
			Rebuild();
		}
	}
	int Calc(int k) const
	{
		k = min(Max, k - del);
		if (k < Min) return 0;
		else return Sum[k];
	}
private:
	int l, r, Min, Max, del, Sum[N];
	bool flag;
}B[(N >> 9) + 5];

void Add(int l, int r, int k)
{
	int _l = l - 1 >> 9, _r = r - 1 >> 9;
	for (int i = _l; i <= _r; i ++)
		B[i].Add(l, r, k);
}

int Calc(int x, int k)
{
	int res = 0, _x = x - 1 >> 9;
	for (int i = 0; i <= _x; i ++)
		res = Inc(res, B[i].Calc(k));
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i += K)
		B[i - 1 >> 9].init(i, min(i + K - 1, n));
	Dp[0] = 1, B[0].Rebuild();
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		Add(Last[x] + 1, i, 1);
		if (Last[x])
			Add(Left[Last[x]] + 1, Last[x], -1);
		Left[i] = Last[x], Last[x] = i;
		Dp[i] = Calc(i, m);
		B[i - 1 >> 9].Rebuild();
	}
	printf("%d\n", Dp[n]);
	return 0;
}