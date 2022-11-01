#pragma GCC optimization ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

const int BLOCK_SIZE = 600;

ll k;
vector<ll> a;
vector<ll> comp_minus_k;
vector<ll> comp;
vector<ll> comp_plus_k;
vector<ll> cnt;
ll answer = 0;

void mo(int old_l, int old_r, int new_l, int new_r) {
	for (int r = old_r + 1; r <= new_r; ++r) {
		answer += cnt[comp_minus_k[r]];
		++cnt[comp[r]];
	}
	for (int r = old_r; r > new_r; --r) {
		--cnt[comp[r]];
		answer -= cnt[comp_minus_k[r]];
	}
	for (int l = old_l - 1; l >= new_l; --l) {
		answer += cnt[comp_plus_k[l]];
		++cnt[comp[l]];
	}
	for (int l = old_l; l < new_l; ++l) {
		--cnt[comp[l]];
		answer -= cnt[comp_plus_k[l]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> k;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		a[i] = (t == 1 ? 1 : -1);
	}
	for (int i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		a[i] *= x;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
	}
	{
		comp_minus_k.resize(n + 1);
		comp.resize(n + 1);
		comp_plus_k.resize(n + 1);
		map<ll, int> values;
		int tmp = 0;
		for (int i = 0; i <= n; ++i) {
			values[a[i]] = values[a[i] + k] = values[a[i] - k] = 0;
		}
		for (auto& now : values) {
			now.second = tmp++;
		}
		for (int i = 0; i <= n; ++i) {
			comp_minus_k[i] = values[a[i] - k];
			comp[i] = values[a[i]];
			comp_plus_k[i] = values[a[i] + k];
		}
		cnt.resize(tmp);
	}
	vector<pair<pair<int, int>, int>> queries;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		queries.push_back({{l, r}, i});
	}
	sort(queries.begin(), queries.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if (a.first.first / BLOCK_SIZE != b.first.first / BLOCK_SIZE) {
			return a.first.first / BLOCK_SIZE < b.first.first / BLOCK_SIZE;
		} else {
			return a.first.second < b.first.second;
		}
	});
	vector<ll> res(q);
	int old_l = 1;
	int old_r = 0;
	for (int i = 0; i < q; ++i) {
		int new_l = queries[i].first.first;
		int new_r = queries[i].first.second;
		mo(old_l, old_r, new_l, new_r);
		res[queries[i].second] = answer;
		old_l = new_l;
		old_r = new_r;
	}
	for (int i = 0; i < q; ++i) {
		cout << res[i] << '\n';
	}
	return 0;
}