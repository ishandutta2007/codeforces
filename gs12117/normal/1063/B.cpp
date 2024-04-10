#include<cstdio>
char s[2010][2010];
int chk[2010][2010];
int dist[2010][2010];
int q[4100000][2];
int qs, qe;
int nq[4100000][2];
int nql;
int n, m;
int sx, sy;
int pl, pr;
int sd;
void qpush(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return;
	if (chk[x][y] != 0 || s[x][y] == '*')return;
	chk[x][y] = 1;
	dist[x][y] = sd;
	q[qe][0] = x;
	q[qe][1] = y;
	qe++;
}
void nqpush(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return;
	if (chk[x][y] != 0 || s[x][y] == '*')return;
	chk[x][y] = 1;
	dist[x][y] = sd + 1;
	nq[nql][0] = x;
	nq[nql][1] = y;
	nql++;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &sx, &sy);
	sx--;
	sy--;
	scanf("%d%d", &pl, &pr);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	qs = 0;
	qe = 1;
	q[0][0] = sx;
	q[0][1] = sy;
	chk[sx][sy] = 1;
	while (qs < qe) {
		while (qs < qe) {
			int x = q[qs][0];
			int y = q[qs][1];
			qs++;
			qpush(x + 1, y);
			qpush(x - 1, y);
			nqpush(x, y + 1);
			nqpush(x, y - 1);
		}
		for (int i = 0; i < nql; i++) {
			q[qe][0] = nq[i][0];
			q[qe][1] = nq[i][1];
			qe++;
		}
		nql = 0;
		sd++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0)continue;
			int rside = (dist[i][j] + j - sy)/2;
			int lside = dist[i][j] - rside;
			if (rside <= pr&&lside <= pl)ans++;
		}
	}
	printf("%d", ans);
	return 0;
}