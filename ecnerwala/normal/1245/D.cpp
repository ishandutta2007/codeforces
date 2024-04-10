#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2100;
int N;
int X[MAXN];
int Y[MAXN];
ll C[MAXN];
ll K[MAXN];

int par[MAXN];
int getPar(int a) {
	return (par[a] == -1) ? a : (par[a] = getPar(par[a]));
}
bool merge(int a, int b) {
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	par[b] = a;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> K[i];
	}
	vector<pair<ll, pair<int, int>>> edges;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			edges.emplace_back((abs(X[i] - X[j]) + abs(Y[i] - Y[j])) * (K[i] + K[j]), pair<int, int>(i,j));
		}
	}
	for (int i = 1; i <= N; i++) {
		edges.emplace_back(C[i], pair<int,int>(0,i));
	}
	sort(edges.begin(), edges.end());
	vector<int> stations;
	vector<pair<int, int>> wires;
	memset(par, -1, sizeof(par));
	ll ans = 0;
	for (auto it : edges) {
		auto e = it.second;
		int a = e.first;
		int b = e.second;
		if (merge(a,b)) {
			ans += it.first;
			if (a == 0) {
				stations.push_back(b);
			} else {
				wires.push_back(e);
			}
		}
	}
	cout << ans << '\n';
	cout << stations.size() << '\n';
	for (int v : stations) { cout << v << ' '; } cout << '\n';
	cout << wires.size() << '\n';
	for (auto e : wires) { cout << e.first << ' ' << e.second << '\n'; }
 
	return 0;
}