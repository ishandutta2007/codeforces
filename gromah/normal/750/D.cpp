#include <cstdio>
#include <algorithm>
using namespace std;
#define N 30 + 5
#define M 2000 + 5
#define K 1000

const int Fx[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int n, ans, A[N], Id[M][M][8], X[2][(M) * (M)], Y[2][(M) * (M)], Dir[2][(M) * (M)];
bool Flag[M][M];

inline void BFS(int sx, int sy)
{
	int d = 1;
	X[0][d] = sx, Y[0][d] = sy, Dir[0][d] = 0;
	for (int i = 0; i < A[1]; i ++)
		Flag[sx + i][sy] = 1;
	for (int i = 2; i <= n; i ++)
	{
		int cnt = 0;
		for (; d; d --)
		{
			int x = X[0][d], y = Y[0][d], dir = Dir[0][d];
			int l_d = dir == 0 ? 7 : dir - 1;
			int r_d = dir == 7 ? 0 : dir + 1;
			int tx, ty;
			for (int t = 1; t <= A[i]; t ++)
			{
				tx = x + Fx[l_d][0] * t;
				ty = y + Fx[l_d][1] * t;
				Flag[tx][ty] = 1;
				tx = x + Fx[r_d][0] * t;
				ty = y + Fx[r_d][1] * t;
				Flag[tx][ty] = 1;
			}
			tx = x + Fx[l_d][0] * A[i];
			ty = y + Fx[l_d][1] * A[i];
			if (Id[tx][ty][l_d] != i)
			{
				cnt ++;
				X[1][cnt] = tx, Y[1][cnt] = ty, Dir[1][cnt] = l_d;
				Id[tx][ty][l_d] = i;
			}
			tx = x + Fx[r_d][0] * A[i];
			ty = y + Fx[r_d][1] * A[i];
			if (Id[tx][ty][r_d] != i)
			{
				cnt ++;
				X[1][cnt] = tx, Y[1][cnt] = ty, Dir[1][cnt] = r_d;
				Id[tx][ty][r_d] = i;
			}
		}
		for (int i = 1; i <= cnt; i ++)
		{
			X[0][i] = X[1][i];
			Y[0][i] = Y[1][i];
			Dir[0][i] = Dir[1][i];
		}
		d = cnt;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	BFS(K, K);
	for (int i = 0; i < M; i ++)
		for (int j = 0; j < M; j ++)
			ans += Flag[i][j];
	printf("%d\n", ans);
	return 0;
}