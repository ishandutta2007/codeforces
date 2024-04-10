#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node {
	ll gs, zd;
}e[200005];
ll ans;
bool cmp(node x, node y) {
	if(x.zd == y.zd) return x.gs < y.gs;
	return x.zd < y.zd;
}
int main() {
	cin >> n;
	ll k, i, v, j;
	for(i = 1; i <= n; ++i) {
		cin >> k;
		e[i].gs = k;
		for(j = 1; j <= k; ++j) {
			cin >> v;
			e[i].zd = max(e[i].zd, v);
		}
	}
	sort(e + 1, e + 1 + n, cmp);
	for(i = 1; i < n; ++i) {
		ans += (e[n].zd - e[i].zd) * e[i].gs;
	}
	cout << ans;
	return 0;
}