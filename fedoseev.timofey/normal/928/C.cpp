#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

map <pair <string, int>, vector <pair <string, int>>> g;
vector <pair <string, int>> ans;
map <string, int> used;
map <string, int> best;
map <string, int> dist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string name;
	int version;
	cin >> name >> version;
	int x;
	cin >> x;
	for (int i = 0; i < x; ++i) {
		string s;
		int a;
		cin >> s >> a;
		g[{name, version}].push_back({s, a});
	}
	for (int i = 0; i < n - 1; ++i) {
		string cur;
		int t;
		cin >> cur >> t;
		dist[cur] = -1;
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; ++i) {
			string s;
			int tmp;
			cin >> s >> tmp;
			g[{cur, t}].push_back({s, tmp});
		}
	}
	queue <pair <string, int>> q;
	q.push({name, version});
	best[name] = version;
	dist[name] = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		string s = p.first;
		int num = p.second;
		if (best[s] != num) continue;
		used[s] = 1;
		if (s != name) ans.push_back({s, num});
		for (auto vp : g[{s, num}]) {
			if (!used[vp.first]) {
				string cur = vp.first;
				int tmp = vp.second;
				if ((dist[cur] == -1 || dist[cur] == dist[s] + 1) && tmp > best[cur]) {
					dist[cur] = dist[s] + 1;
					best[cur] = tmp;
					q.push({cur, tmp});
				}
			}
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}