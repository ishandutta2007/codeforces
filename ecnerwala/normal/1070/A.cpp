#include <bits/stdc++.h>
using namespace std;

int d, s;
int dp[6100][610];
int mul[6100 * 610];
bool used[6100][610];
int len;
int xx[6100 * 610], yy[6100 * 610];

void out(int x, int y) {
	if (dp[x][y] == 0)
		return ;
	bool Find = false;
	for (int i = 0; i < 10 && i <= x && !Find; i++) {
		if (dp[x - i][(((y - mul[dp[x][y] - 1] * i) % d) + d) % d] <= dp[x][y] - 1) {
			printf("%d", i);
			int diff = dp[x][y] - dp[x - i][(((y - mul[dp[x][y] - 1] * i) % d) + d) % d];
			for (int j = 1; j < diff; j++)
				printf("0");
			Find = true;
			out(x - i, ((y - mul[dp[x][y] - 1] * i) % d + d) % d);
		}
	}
	assert(Find);
}

int main() {
	scanf("%d%d", &d, &s);
	
	mul[0] = 1;
	for (int i = 1; i <= d * s; i++)
		mul[i] = 10 * mul[i - 1] % d;
	
	dp[0][0] = 0;
	int q = 1, h = 1;
	xx[1] = 0;
	yy[1] = 0;
	used[0][0] = true;

	while (q <= h) {
		for (int i = 0; i < 10; i++) {
			int X = xx[q] + i, Y = (yy[q] * 10 + i) % d;
			if (X <= s && !used[X][Y]) {
				used[X][Y] = true;
				dp[X][Y] = dp[xx[q]][yy[q]] + 1;
				h++;
				xx[h] = X;
				yy[h] = Y;
			}
		}
		q++;
	}
	if (!used[s][0]) {
		printf("-1\n");
	}else {
		out(s, 0);
	}
	
}