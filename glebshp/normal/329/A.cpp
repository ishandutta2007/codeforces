#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200;

char field[size][size];

bool isfree(int x, int y) {
	return field[x][y] == '.';
}

int n;

bool used[size];
int pr[size];

bool dfs(int v) {
	if (used[v])
		return false;
	used[v] = true;
	for (int i = 0; i < n; i++)
		if (isfree(v, i) && (pr[i] == -1 || dfs(pr[i]))) {
			pr[i] = v;
			return true;
		}

	return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", field[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool flag = false;
			for (int k = 0; k < n; k++)
				flag = flag || isfree(i, k) || isfree(k, j);
		
			if (!flag) {
				printf("-1\n");
				return 0;
			}
		}
	}

	vector <pair <int, int> > ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (isfree(i, j)) {
				ans.pb(mp(i, j));
				break;
			}
	}

	if ((int)ans.size() != n) {
		ans.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (isfree(j, i)) {
					ans.pb(mp(j, i));
					break;
				}
			}
	}

	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i].fs + 1 << ' ' << ans[i].sc + 1 << endl;

    return 0;
}