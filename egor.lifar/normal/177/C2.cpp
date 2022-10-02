#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, k, m;
vector<int> v[100000];
vector<int> v1[100000];
queue<int> q;
bool b[100000];
int ans = 0;
bool used[100000];
bool used1[100000];
bool t = true;
int sum = 0;


void bfs(int i) {
	q.push(i);
	for (int g = 0; g < (int)v1[i].size(); g++) {
		int h = v1[i][g];
		b[h] = true;
		if (used[h]) {
			t = false;
		}
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		used1[a] = true;
		used[a] = true;
		sum++;
		for (int j = 0; j < (int)v[a].size(); j++) {
			int x = v[a][j];
			if (b[x]) {
				t = false;
			}
			if (!used[x]) {
				used[x] = true;
				q.push(x);
				for (int g = 0; g < (int)v1[x].size(); g++) {
					int h = v1[x][g];
					b[h] = true;
					if (used[h]) {
						t = false;
					}
				}
			}
		}
	}
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (used1[i]) {
			continue;
		}
		memset(used, 0, sizeof(used));
		memset(b, 0, sizeof(b));
		sum = 0;
		t = true;
		bfs(i);
		if (t) {
			ans = max(ans, sum);
		//	cout << sum << ' ' << i + 1 << endl;
		}
	}
	cout << ans << endl;
    return 0;
}