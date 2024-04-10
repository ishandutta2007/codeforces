#include <bits/stdc++.h>
using namespace std;

const int nax = 2e5 + 5;
vector<int> prime_divisors[nax];
// 100 -> {2, 5}
vector<int> edges[nax];
bool is_marked[nax], vis[nax];

void dfs(int a, int parent, int dist, pair<int,int>& furthest) {
	// cerr << a << " par=" << parent << " dist=" << dist << endl;
	vis[a] = true;
	furthest = max(furthest, make_pair(dist, a));
	for(int b : edges[a]) {
		if(b != parent && is_marked[b]) {
			dfs(b, a, dist + 1, furthest);
		}
	}
}

int get_longest_path(vector<int> group) {
	for(int v : group) {
		is_marked[v] = true;
	}
	int longest_path = 0;
	for(int v : group) {
		if(!vis[v]) {
			pair<int,int> furthest{-1, -1};
			// cerr << "1" << endl;
			dfs(v, -1, 1, furthest);
			int start = furthest.second;
			furthest = {-1, -1};
			// cerr << "2" << endl;
			dfs(start, -1, 1, furthest);
			longest_path = max(longest_path, furthest.first);
		}
	}
	for(int v : group) {
		is_marked[v] = false;
		vis[v] = false;
	}
	return longest_path;
}
vector<int> group[nax];

int main() {
	for(int i = 2; i < nax; ++i) {
		if(prime_divisors[i].empty()) {
			for(int j = i; j < nax; j += i) {
				prime_divisors[j].push_back(i);
			}
		}
	}
	
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		for(int p : prime_divisors[a[i]]) {
			group[p].push_back(i);
		}
	}
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	int answer = 0;
	for(int p = 0; p < nax; ++p) {
		if(!group[p].empty()) {
			answer = max(answer, get_longest_path(group[p]));
		}
	}
	printf("%d\n", answer);
}