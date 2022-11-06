#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define INF 3000000000000000000LL

int Case, n;
LL T[N][4], X[N], Y[N], Z[N], Max[4], Min[4], L[4], R[4];

inline LL Abs(LL x)
{
	return x > 0 ? x : -x;
}

inline LL Calc(LL x, LL y, LL z)
{
	LL res = 0;
	for (int i = 1; i <= n; i ++)
		res = max(res, Abs(x - X[i]) + Abs(y - Y[i]) + Abs(z - Z[i]));
	return res;
}

inline void Get(LL &x, LL &y, LL &z)
{
	LL _x = (x + y) / 2;
	LL _y = (x + z) / 2;
	LL _z = (y + z) / 2;
	x = _x, y = _y, z = _z;
	LL Min = Calc(x, y, z);
	for (int i = -1; i <= 1; i ++)
		for (int j = -1; j <= 1; j ++)
			for (int k = -1; k <= 1; k ++)
			{
				LL t = Calc(_x + i, _y + j, _z + k);
				if (t < Min) Min = t, x = _x + i, y = _y + j, z = _z + k;
			}
}

inline bool Check(LL dis, LL &x, LL &y, LL &z)
{
	for (int i = 0; i < 4; i ++)
	{
		L[i] = Max[i] - dis, R[i] = Min[i] + dis;
		if (L[i] > R[i]) return 0;
	}
	LL _x = R[1], _y = R[2], _z = R[3];
	if (_x + _y + _z < L[0] || L[1] + L[2] + L[3] > R[0]) return 0;
	if (_x + _y + _z <= R[0])
		Get(_x, _y, _z);
	else if (_x + _y + L[3] <= R[0])
	{
		_z = max(L[3], L[0] - _x - _y);
		Get(_x, _y, _z);
	}
	else if (_x + L[2] + L[3] <= R[0])
	{
		_z = L[3];
		_y = max(L[2], L[0] - _x - _z);
		Get(_x, _y, _z);
	}
	else
	{
		_y = L[2], _z = L[3];
		_x = max(L[1], L[0] - _y - _z);
		Get(_x, _y, _z);
	}
	x = _x, y = _y, z = _z;
	return 1;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			LL x, y, z;
			scanf("%I64d%I64d%I64d", &x, &y, &z);
			X[i] = x, Y[i] = y, Z[i] = z;
			for (int k = 0; k < 4; k ++)
			{
				T[i][k] = x + y * ((k & 2) ? -1 : 1) + z * ((k & 1) ? -1 : 1);
				if (k == 3) T[i][k] = -T[i][k];
				Min[k] = i == 1 ? T[i][k] : min(Min[k], T[i][k]);
				Max[k] = i == 1 ? T[i][k] : max(Max[k], T[i][k]);
			}
		}
		LL l = 0, r = INF, ans_x = 0, ans_y = 0, ans_z = 0;
		while (l < r)
		{
			LL mid = (l >> 1) + (r >> 1) + (l & r & 1);
			if (Check(mid, ans_x, ans_y, ans_z)) r = mid;
				else l = mid + 1;
		}
		printf("%I64d %I64d %I64d\n", ans_x, ans_y, ans_z);
	}
	return 0;
}