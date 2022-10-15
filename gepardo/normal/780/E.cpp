#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>

using namespace std;

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
    #else
		ios_base::sync_with_stdio(false);
    #endif // DEBUG
    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<int> > g(n);
    for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
    }
    vector<char> used(n, false);
    vector< vector<int> > ways(k);
    vector<int> q;
	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		for (int to: g[v]) {
			if (!used[to]) {
				q.push_back(to+1);
				dfs(to);
				q.push_back(v+1);
			}
		}
	};
	q.push_back(1);
    dfs(0);
    int l = q.size();
    int roomCnt = (2 * n + k - 1) / k;
	for (int i = 0; i < k; i++) {
		if (roomCnt * i >= l) {
			ways[i].push_back(1);
		} else {
			for (int ptr = roomCnt * i; ptr < roomCnt * (i+1) && ptr < l; ptr++) {
                ways[i].push_back(q[ptr]);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cout << ways[i].size();
		for (int j = 0; j < (int)ways[i].size(); j++) {
			cout << " " << ways[i][j];
		}
		cout << "\n";
	}
	return 0;
}