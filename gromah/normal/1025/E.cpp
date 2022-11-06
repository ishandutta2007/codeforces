#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 50 + 5
#define M 2500 + 5
#define mp make_pair

const int Fx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, Sx[N], Sy[N], Tx[N], Ty[N], Map[N][N], q[M][2], Fa[N][N][2], Ord[N];
bool Flag[N][N];

struct Step
{
	int x1, y1, x2, y2;
	Step (int x1, int y1, int x2, int y2)
	  : x1(x1), y1(y1), x2(x2), y2(y2) {
	}
	void out() const
	{
		printf("%d %d %d %d\n", x1, y1, x2, y2);
	}
};

vector <Step> Ans;

void Debug()
{
	puts("------------------------");
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			printf("%d%c", Map[i][j], j == n ? '\n' : ' ');
	puts("------------------------");
}

void Move(int x1, int y1, int x2, int y2)
{
	if (Map[x1][y1] || Map[x2][y2])
	{
		swap(Map[x1][y1], Map[x2][y2]);
		Ans.push_back(Step(x1, y1, x2, y2));
	}
}

void BFS(int x, int y)
{
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			Fa[i][j][0] = Fa[i][j][1] = Flag[i][j] = 0;
	Flag[x][y] = 1;
	int l = 1, r = 1;
	q[1][0] = x, q[1][1] = y;
	while (l <= r)
	{
		int cx = q[l][0], cy = q[l][1];
		l ++;
		if (Map[cx][cy])
		{
			for (int tx, ty; cx && cy; cx = tx, cy = ty)
			{
				tx = Fa[cx][cy][0], ty = Fa[cx][cy][1];
				if (tx && ty)
					Move(cx, cy, tx, ty);
			}
			return ;
		}
		for (int k = 0; k < 4; k ++)
		{
			int tx = cx + Fx[k][0], ty = cy + Fx[k][1];
			if (tx > 1 && tx <= n && ty >= 1 && ty <= n && !Flag[tx][ty])
			{
				Flag[tx][ty] = 1;
				r ++;
				q[r][0] = tx, q[r][1] = ty;
				Fa[tx][ty][0] = cx, Fa[tx][ty][1] = cy;
			}
		}
	}
}

void Rotate(int st, int ed)
{
	if (st == ed) return ;
	Move(1, st, 2, st);
	for (int i = st; i > ed; i --)
	{
		Move(1, i - 1, 1, i);
		Move(2, i, 2, i - 1);
	}
	Move(2, ed, 1, ed);
}

void Go(int sx, int sy, int tx, int ty)
{
	if (sy >= ty)
	{
		for (int i = sx; i < tx; i ++)
			Move(i, sy, i + 1, sy);
		for (int i = sy; i > ty; i --)
			Move(tx, i, tx, i - 1);
	}
	else
	{
		for (int i = sy; i < ty; i ++)
			Move(sx, i, sx, i + 1);
		for (int i = sx; i < tx; i ++)
			Move(i, ty, i + 1, ty);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d", Sx + i, Sy + i);
		Map[Sx[i]][Sy[i]] = i;
	}
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d", Tx + i, Ty + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + m + 1, [&](int u, int v){
		return mp(Tx[u], Ty[u] * (Tx[u] > 1 ? -1 : 1)) < mp(Tx[v], Ty[v] * (Tx[v] > 1 ? -1 : 1));
	});
	if (n == 1) puts("0");
	else
	{
		//Debug();
		for (int i = 1; i <= n; i ++)
			if (!Map[1][i]) BFS(1, i);
		for (int i = 1; i <= m; i ++)
		{
			int id = Ord[i], pos = 0;
			for (int j = 1; !pos && j <= n; j ++)
				if (Map[1][j] == id) pos = j;
			Rotate(pos, i);
		}
		for (int i = m; i; i --)
			Go(1, i, Tx[Map[1][i]], Ty[Map[1][i]]);
		//Debug();
		printf("%d\n", Ans.size());
		for (const Step& step : Ans)
			step.out();
	}
	return 0;
}