#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2100000000

int n, x, y, Min[8][2];
char ch[9];

int main()
{
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	for (int i = 0; i < 8; i ++)
		Min[i][0] = Min[i][1] = INF;
	while (n --)
	{
		int u, v;
		scanf("%s%d%d", ch, &u, &v);
		u -= x, v -= y;
		bool op_0 = (ch[0] != 'B');
		if (!u)
		{
			if (v > 0) Min[0][op_0] = min(Min[0][op_0], v);
				else Min[4][op_0] = min(Min[4][op_0], -v);
		}
		else if (!v)
		{
			if (u > 0) Min[2][op_0] = min(Min[2][op_0], u);
				else Min[6][op_0] = min(Min[6][op_0], -u);
		}
		bool op_1 = (ch[0] != 'R');
		if (u == v)
		{
			if (u > 0) Min[1][op_1] = min(Min[1][op_1], u);
				else Min[5][op_1] = min(Min[5][op_1], -u);
		}
		else if (u == -v)
		{
			if (u > 0) Min[3][op_1] = min(Min[3][op_1], u);
				else Min[7][op_1] = min(Min[7][op_1], -u);
		}
	}
	bool ok = 0;
	for (int i = 0; !ok && i < 8; i ++)
		ok = (Min[i][1] < Min[i][0]);
	if (ok) puts("YES");
		else puts("NO");
	return 0;
}