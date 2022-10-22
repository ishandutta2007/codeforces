#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;

char gtc() {return p1 == p2 && (p2 = buf + fread(p1 = buf, 1, 1 << 20, stdin)) == p1 ? EOF : *p1++;}

void read(int &x) {
	char c = gtc();
	while (c < '0' || c > '9') c = gtc();
	x = c - '0', c = gtc();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gtc();
}

int head[500010], nxt[1000010], to[1000010], tag[500010], dep[500010], in[500010], alive[500010], TOT;
char s[500010];

void add_edge(int x, int y) {
	to[TOT] = y, nxt[TOT] = head[x], head[x] = TOT++;
}

void dfs(int x, int last) {
	for (int i = head[x]; ~i; i = nxt[i]) {
		int v = to[i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x);
	}
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			head[i] = -1, tag[i] = 0, in[i] = 0;
		}
		TOT = 0;
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			add_edge(x, y), add_edge(y, x);
			in[x]++, in[y]++;
		}
		scanf("%s", s + 1);
		int k = 0;
		for (int i = 1; i <= n; i++) {
			tag[i] = s[i] == 'W';
			k += tag[i];
		}
		if (n <= 2) {
			printf("Draw\n");
			continue;
		}
		if (n == 3) {
			if (k >= 2) printf("White\n");
			else printf("Draw\n");
			continue;
		}
		if (k > 2) {
			printf("White\n");
			continue;
		}
		dep[1] = 0, dfs(1, 1);
		int X = -1, Y = -1, lst = -1;
		for (int i = 1; i <= n; i++) {
			if (in[i] > 3) {
				printf("White\n");
				goto END;
			}
			if (in[i] > 2 && tag[i]) {
				printf("White\n");
				goto END;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (tag[i]) {
				if (X == -1) X = i;
				else Y = i;
			}
		}
		if (X != -1 && Y != -1 && (dep[X] + dep[Y]) % 2 == 0) {
			printf("White\n");
			continue; 
		}
		for (int i = 1; i <= n; i++) {
			if (in[i] == 3) {
				int cnt = 0;
				for (int j = head[i]; ~j; j = nxt[j]) {
					if (in[to[j]] > 1) cnt++;
				}
				if (cnt >= 2) {
					printf("White\n");
					goto END;
				}
				if (X != -1 && (dep[i] + dep[X]) % 2 == 1) {
					printf("White\n");
					goto END;
				}
				if (Y != -1 && (dep[i] + dep[Y]) % 2 == 1) {
					printf("White\n");
					goto END;
				}
				if (lst != -1 && (dep[i] + dep[lst]) % 2 == 0) {
					printf("White\n");
					goto END;
				}
				lst = i;
			}
			if (tag[i] && in[i] == 2) {
				int cnt = 0;
				for (int j = head[i]; ~j; j = nxt[j]) {
					if (in[to[j]] > 1) cnt++;
				}
				if (cnt) {
					printf("White\n");
					goto END;
				}
			}
		}
		printf("Draw\n");
		END:;
	}
	return 0;
}
/*
2
4
1 2
1 3
1 4
0
7
1 2
2 3
3 4
4 5
5 6
6 7
2
1 7

*/