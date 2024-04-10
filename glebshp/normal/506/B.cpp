#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;

vector <int> vertex[size];
vector <int> dir[size];
int n, m;
int col[size];
bool used[size];
vector <int> cur;
bool flag = false;

void dfs1(int v) {
	used[v] = true;
	cur.pb(v);
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (!used[vertex[v][i]]) {
			dfs1(vertex[v][i]);
		}
}

void dfs2(int v) {
	col[v] = 1;
	for (int i = 0; i < (int) dir[v].size(); i++) {
		if (col[dir[v][i]] == 2)
			continue;
		if (col[dir[v][i]] == 1) {
			flag = true;
		}
		if (col[dir[v][i]] == 0) {
			dfs2(dir[v][i]);
		}
	}

	col[v] = 2;
}

int main() {
	int v, u;
	int ans = 0;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;

		vertex[v].pb(u);
		vertex[u].pb(v);

		dir[v].pb(u);
	}

	for (int i = 0; i < n; i++)
		if (!used[i]) {
			cur.clear();
			dfs1(i);

			flag = false;
			for (int j = 0; j < (int) cur.size(); j++)
				if (col[cur[j]] == 0)
					dfs2(cur[j]);

			ans += cur.size();
			if (!flag)
				ans--;
		}

	cout << ans << endl;

	return 0;
}