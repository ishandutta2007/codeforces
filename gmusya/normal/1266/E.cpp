#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ll long long 
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, map <int, ll>> kek;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll cur_ans = 0;
	for (ll i = 0; i < n; i++)
		cur_ans += a[i];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		--s;
		kek[s][t] += 1;
		kek[s][t] -= 1;
		int x = kek[s][t];
		if (x != 0) {
			--x;
			if (a[x] >= 0)
				++cur_ans;
			++a[x];
			if (u == 0)
				kek[s][t] = u;
		}
		if (u != 0) {
			kek[s][t] = u;
			--u;
			if (a[u] > 0)
				--cur_ans;
			--a[u];
		}
		cout << cur_ans << endl;
	}
	return 0;
}