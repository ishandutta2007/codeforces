#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
#define N 100000 + 5

int t_x, t_y, n, Min[2][2], X[N], Y[N], _X[2], _Y[2];
LD res;

inline LD Dis(int x_1, int y_1, int x_2, int y_2)
{
	int _x = x_1 - x_2, _y = y_1 - y_2;
	LL tmp = 1LL * _x * _x + 1LL * _y * _y;
	return sqrt(1.0 * tmp);
}

inline void Update(LD dis, int id, int op)
{
	if (!Min[op][1] || Dis(_X[op], _Y[op], X[Min[op][1]], Y[Min[op][1]]) - Dis(t_x, t_y, X[Min[op][1]], Y[Min[op][1]]) > dis)
	{
		if (!Min[op][0] || Dis(_X[op], _Y[op], X[Min[op][0]], Y[Min[op][0]]) - Dis(t_x, t_y, X[Min[op][0]], Y[Min[op][0]]) > dis)
			Min[op][1] = Min[op][0], Min[op][0] = id;
		else Min[op][1] = id;
	}
}

int main()
{
	scanf("%d%d%d%d%d%d", _X, _Y, _X + 1, _Y + 1, &t_x, &t_y);
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i ++)
	{
		scanf("%d%d", X + i, Y + i);
		Update(Dis(_X[0], _Y[0], X[i], Y[i]) - Dis(t_x, t_y, X[i], Y[i]), i, 0);
		Update(Dis(_X[1], _Y[1], X[i], Y[i]) - Dis(t_x, t_y, X[i], Y[i]), i, 1);
		res += 2.0 * Dis(t_x, t_y, X[i], Y[i]);
	}
	if (n == 1)
	{
		LD tmp_0, tmp_1;
		tmp_0 = Dis(_X[0], _Y[0], X[1], Y[1]) - Dis(t_x, t_y, X[1], Y[1]);
		tmp_1 = Dis(_X[1], _Y[1], X[1], Y[1]) - Dis(t_x, t_y, X[1], Y[1]);
		res += min(tmp_0, tmp_1);
		goto Output;
	}
	if (Min[0][0] == Min[1][0])
	{
		LD tmp_0, tmp_1, tmp_2, tmp_3;
		tmp_0 = Dis(_X[0], _Y[0], X[Min[0][0]], Y[Min[0][0]]) - Dis(t_x, t_y, X[Min[0][0]], Y[Min[0][0]]);
		tmp_1 = Dis(_X[1], _Y[1], X[Min[1][1]], Y[Min[1][1]]) - Dis(t_x, t_y, X[Min[1][1]], Y[Min[1][1]]);
		tmp_2 = Dis(_X[0], _Y[0], X[Min[0][1]], Y[Min[0][1]]) - Dis(t_x, t_y, X[Min[0][1]], Y[Min[0][1]]);
		tmp_3 = Dis(_X[1], _Y[1], X[Min[1][0]], Y[Min[1][0]]) - Dis(t_x, t_y, X[Min[1][0]], Y[Min[1][0]]);
		tmp_0 = min(tmp_0, tmp_1) + min(max(tmp_0, tmp_1), (LD) 0.0);
		tmp_1 = min(tmp_2, tmp_3) + min(max(tmp_2, tmp_3), (LD) 0.0);
		res += min(tmp_0, tmp_1);
	}
	else
	{
		LD tmp_0, tmp_1;
		tmp_0 = Dis(_X[0], _Y[0], X[Min[0][0]], Y[Min[0][0]]) - Dis(t_x, t_y, X[Min[0][0]], Y[Min[0][0]]);
		tmp_1 = Dis(_X[1], _Y[1], X[Min[1][0]], Y[Min[1][0]]) - Dis(t_x, t_y, X[Min[1][0]], Y[Min[1][0]]);
		res += min(tmp_0, tmp_1) + min(max(tmp_0, tmp_1), (LD) 0.0);
	}
	
	Output :;
	
	printf("%.12lf\n", (double) res);
	return 0;
}