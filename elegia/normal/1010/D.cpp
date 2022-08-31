#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include <numeric>
#include <functional>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1000010;

int n;
int t[N], ch[N][2];
bool res[N];
bool fun[N][2];
char s[10];

void dfs(int u);
void dfs2(int u);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		switch (s[0]) {
			case 'A': // AND
				scanf("%d%d", &ch[i][0], &ch[i][1]);
				t[i] = 2;
				break;
			case 'O': // OR
				scanf("%d%d", &ch[i][0], &ch[i][1]);
				t[i] = 3;
				break;
			case 'X': // XOR
				scanf("%d%d", &ch[i][0], &ch[i][1]);
				t[i] = 4;
				break;
			case 'N': // NOT
				scanf("%d", &ch[i][0]);
				t[i] = 1;
				break;
			case 'I': // IN
				scanf("%d", &ch[i][0]);
				break;
		}
	}
	dfs(1);
	fun[1][1] = 1;
	dfs2(1);
	for (int i = 1; i <= n; ++i)
		if (t[i] == 0)
			printf("%d", fun[i][!res[i]]);
	return 0;
}

void dfs(int u) {
	switch (t[u]) {
		case 0: // IN
			res[u] = ch[u][0];
			break;
		case 1: // NOT
			dfs(ch[u][0]);
			res[u] = !res[ch[u][0]];
			break;
		case 2:
			dfs(ch[u][0]);
			dfs(ch[u][1]);
			res[u] = res[ch[u][0]] && res[ch[u][1]];
			break;
		case 3:
			dfs(ch[u][0]);
			dfs(ch[u][1]);
			res[u] = res[ch[u][0]] || res[ch[u][1]];
			break;
		case 4:
			dfs(ch[u][0]);
			dfs(ch[u][1]);
			res[u] = res[ch[u][0]] ^ res[ch[u][1]];
			break;
	}
}

void dfs2(int u) {
	switch (t[u]) {
		case 0: // IN
			break;
		case 1: // NOT
			fun[ch[u][0]][0] = fun[u][1];
			fun[ch[u][0]][1] = fun[u][0];
			dfs2(ch[u][0]);
			break;
		case 2: // AND
			fun[ch[u][0]][0] = fun[u][0];
			fun[ch[u][0]][1] = fun[u][res[ch[u][1]]];
			fun[ch[u][1]][0] = fun[u][0];
			fun[ch[u][1]][1] = fun[u][res[ch[u][0]]];
			dfs2(ch[u][0]);
			dfs2(ch[u][1]);
			break;
		case 3: // OR
			fun[ch[u][0]][0] = fun[u][res[ch[u][1]]];
			fun[ch[u][0]][1] = fun[u][1];
			fun[ch[u][1]][0] = fun[u][res[ch[u][0]]];
			fun[ch[u][1]][1] = fun[u][1];
			dfs2(ch[u][0]);
			dfs2(ch[u][1]);
			break;
		case 4: // XOR
			fun[ch[u][0]][0] = fun[u][res[ch[u][1]]];
			fun[ch[u][0]][1] = fun[u][!res[ch[u][1]]];
			fun[ch[u][1]][0] = fun[u][res[ch[u][0]]];
			fun[ch[u][1]][1] = fun[u][!res[ch[u][0]]];
			dfs2(ch[u][0]);
			dfs2(ch[u][1]);
			break;
	}
}