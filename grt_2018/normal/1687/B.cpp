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

int n, m;

ll ask(string s) {
	cout << "? " << s << endl;
	ll x;
	cin >> x;
	return x;
}

const int nax = 510;
char t[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<ll,int>>ind = {};
	for(int i = 1; i <= m; ++i) {
		string tmp2 = "";
		for(int j = 1; j < i; ++j) tmp2 += "0";
		tmp2 += "1";
		for(int j = i + 1; j <= m; ++j) tmp2 += "0";
		ll w = ask(tmp2);
		ind.PB({w, i});
	}
	sort(ind.begin(), ind.end());
	ll sum = 0;
	for(int i = 1; i <= m; ++i) t[i] = '0';
	for(auto [w, id] : ind) {
		string s = "";
		t[id] = '1';
		for(int i = 1; i <= m; ++i) {
			s += t[i];
		}
		ll a = ask(s);
		if(a != sum + w) {
			t[id] = '0';
		} else {
			sum = a;
		}
	}
	cout << "! " << sum << endl;
}