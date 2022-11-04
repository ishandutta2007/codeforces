#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> parent, sum, arr, rang;
	vector<bool> have;
	DSU(vector<ll>& arr): arr(arr) {
		parent.resize(arr.size(), 0);
		sum = arr;
		have.resize(arr.size(), false);
		rang.resize(arr.size(), 1);
		for (ll i = 0; i < arr.size(); i++) {
			parent[i] = i;
			sum[i] = arr[i];
		}
	}
	ll get(ll v) {
		if (v == parent[v]) {
			return v;
		}
		return parent[v] = get(parent[v]);
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (rang[a] < rang[b]) {
			swap(a, b);
		}
		parent[b] = a;
		rang[a] += rang[b];
		sum[a] += sum[b];
	}
	ll unite(ll n) {
		if (n < arr.size()-1) {
			if (have[n+1]) {
				unite(n, n+1);
			}
		}
		if (n > 0) {
			if (have[n-1]) {
				unite(n, n-1);
			}
		}
		have[n] = true;
		return sum[get(n)];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DSU d(arr);
	vector<ll> del(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> del[i];
		del[i]--;
	}
	ll maxx = 0;
	vector<ll> ans;
	reverse(del.begin(), del.end());
	for (ll i = 0; i < n; i++) {
		ans.push_back(maxx);
		maxx = max(maxx, d.unite(del[i]));
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << '\n';
	}
}