#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 3e5+5;

struct player {
	ll x, y;
	int idx;
	bool operator < (const player &p) const {
		return y - x < p.y - p.x;
	}
};

ll ans[ms];
player p[ms];
player p2[ms];
ll somaX[ms], somaY[ms];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].idx = i;
		p2[i] = p[i];
	}
	sort(p, p + n);
	for(int i = 0; i < n; i++) {
		somaX[i+1] = somaX[i] + p[i].x;
		somaY[i+1] = somaY[i] + p[i].y;
	}
	for(int i = 0; i < n; i++) {
		ans[p[i].idx] = i*p[i].x + somaY[i] + (n-i-1)*p[i].y + somaX[n] - somaX[i+1];
		//cout << p[i].idx << ' ' << ans[p[i].idx] << ' ' << i << endl;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		ll score = min(p2[u].x + p2[v].y, p2[u].y + p2[v].x);
		ans[u] -= score;
		ans[v] -= score;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}