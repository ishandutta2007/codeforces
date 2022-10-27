#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int a[maxn], p[maxn];

int find(int v){
	return (p[v] < 0)?v:(p[v] = find(p[v]));
}

long long combine(int u, int v, long long w){
	u = find(u); v = find(v);
	if(u == v)return 0;
	long long ret = w*p[u]*p[v];
	if(p[u] > p[v])swap(u, v);
	p[u] += p[v]; p[v] = u;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; p[i] = -1;
	}
	vector<array<int, 3> > vec;
	for(int i = 1; i <= m; i++){
		int u; cin >> u;
		int v; cin >> v;
		vec.push_back({min(a[u], a[v]), u, v});
	}
	sort(vec.rbegin(), vec.rend());
	long double ans = 0;
	for(auto x : vec){
		ans += combine(x[1], x[2], x[0]);
	}
	ans /= n; ans /= n - 1; ans *= 2;
	cout << fixed << setprecision(10) << ans << '\n';

	return 0;
}