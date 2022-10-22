#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 500 * 1000 + 10;
int n, m;
ll k;
int inv[2 * nax];
int a[nax];
int b[nax];
int cnt[nax];
int licz[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		inv[a[i]] = i + 1;
	}
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < n; ++i) {
		cnt[((ll)m * i)%n]++;
	}
	ll all = 0;
	for(int i = 0; i < m; ++i) {
		if(inv[b[i]] == 0) continue;
		int rest = ((inv[b[i]] - 1) - i + n) % n;
		if(rest < 0) rest += n;
		licz[rest]++;
		all += cnt[rest];
	}
	all = ((ll)m * n - all);
	//cout << all << "\n";
	if(all == 0) {
		cout << "1";
		return 0;
	}
	ll w = (k-1)/all;
	k -= w * all;
	ll L = w * n;
	for(int i = 0;; ++i) {
		//cout << k << " ";
		if(k > m - (licz[((ll)i *m)%n])) {
			k -= m - (licz[((ll)i *m)%n]);
		} else {
			break;
		}
		L++;
	}
	//cout << L << "\n";
	ll day = L * m + 1;
	//cout << k << " " << day << "\n";
	if(k == 0) day--;
	while(k > 0) {
		if(b[(day-1) % m] != a[(day-1) % n]) {
			k--;
		}
		if(k == 0) break;
		day++;
	}
	cout << day;
}