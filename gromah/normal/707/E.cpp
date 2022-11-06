#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 2000 + 5
#define M 1000000 + 5
#define mp make_pair

int n, m, k, q, s, tot, Size[N], Q[N], Op[M][5];
LL Map[N][N], T[N], Cnt[N][N];
bool Flag[N];
char S[9];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

struct Garland
{
	int x, y, w;
	Garland (int _x = 0, int _y = 0, int _w = 0) {x = _x, y = _y, w = _w;}
	bool operator < (const Garland a) const
	{
		return mp(x, y) < mp(a.x, a.y);
	}
}A[N][N];

struct Ask
{
	int x, y;
	Ask (int _x = 0, int _y = 0) {x = _x, y = _y;}
	bool operator < (const Ask a) const
	{
		return mp(x, y) < mp(a.x, a.y);
	}
}E[N << 2];

inline void Modify(int x, int w)
{
	for (; x <= m; x += (x & -x))
		T[x] += w;
}

inline LL Query(int x)
{
	LL res = 0;
	for (; x; x -= (x & -x))
		res += T[x];
	return res;
}

int main()
{
	n = getint(), m = getint(), k = getint();
	for (int i = 1; i <= k; i ++)
	{
		Size[i] = getint();
		for (int j = 1; j <= Size[i]; j ++)
		{
			int x = getint(), y = getint(), w = getint();
			A[i][j] = Garland(x, y, w);
		}
		sort(A[i] + 1, A[i] + Size[i] + 1);
	}
	q = getint();
	for (int i = 1; i <= q; i ++)
	{
		scanf("%s", S);
		if (S[0] == 'S') Op[i][0] = 0, Op[i][1] = getint();
		else
		{
			Op[i][0] = 1;
			for (int j = 1; j <= 4; j ++)
				Op[i][j] = getint();
			Q[++ s] = i;
			E[++ tot] = Ask(Op[i][1] - 1, Op[i][2] - 1);
			E[++ tot] = Ask(Op[i][3], Op[i][2] - 1);
			E[++ tot] = Ask(Op[i][1] - 1, Op[i][4]);
			E[++ tot] = Ask(Op[i][3], Op[i][4]);
		}
	}
	sort(E + 1, E + tot + 1);
	for (int o = 1; o <= k; o ++)
	{
		for (int i = 1; i <= m; i ++) T[i] = 0;
		for (int i = 1, t = 1; i <= tot; i ++)
		{
			for (; t <= Size[o] && (mp(A[o][t].x, A[o][t].y) <= mp(E[i].x, E[i].y)); t ++)
				Modify(A[o][t].y, A[o][t].w);
			Map[E[i].x][E[i].y] = Query(E[i].y);
		}
		for (int i = 1; i <= s; i ++)
		{
			int t = Q[i];
			int x_1 = Op[t][1] - 1, y_1 = Op[t][2] - 1;
			int x_2 = Op[t][3], y_2 = Op[t][4];
			Cnt[o][i] = Map[x_2][y_2] - Map[x_1][y_2] - Map[x_2][y_1] + Map[x_1][y_1];
		}
	}
	for (int i = 1; i <= k; i ++)
		Flag[i] = 1;
	for (int i = 1, t = 0; i <= q; i ++)
	{
		if (!Op[i][0]) Flag[Op[i][1]] ^= 1;
		else
		{
			LL res = 0;
			t ++;
			for (int j = 1; j <= k; j ++)
				if (Flag[j]) res += Cnt[j][t];
			printf("%I64d\n", res);
		}
	}
	return 0;
}