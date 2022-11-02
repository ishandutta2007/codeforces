#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000000 * 2 + 5;
int n;
int pa[maxN], sz[maxN];
int load[maxN];

int findset(int x) {
	return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n * 2; ++i) pa[i] = i, sz[i] = 1;
	memset(load, 0, sizeof(load));
	map<int, int> M;
	for(int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		if(!M.count(x)) M.emplace(x, M.size() + 1);
		if(!M.count(y)) M.emplace(y, M.size() + 1);
		x = M[x]; y = M[y];
		x = findset(x); y = findset(y);
		if(x == y) load[x]++;
		else {
			load[x] += load[y];
			pa[y] = x; sz[x] += sz[y];
		}
	}
	int mx = 0;
	for(auto p : M) mx = max(mx, load[p.second]);
	if(mx > 1) {
		cout << -1 << endl;
		return 0;
	}
	for(map<int, int>::reverse_iterator i = M.rbegin(); i != M.rend(); ++i) {
		int x = findset(i->second);
		if(++load[x] > 1) {
			cout << i->first << endl;
			return 0;
		}
	}
	return 0;
}