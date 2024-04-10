/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 201010
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

bool cmp(const ll& a, const ll& b) {
	return a > b;
}
void solve() {
	ll N;
	cin >> N;
	ll i;
	map<ll, vector<ll>> mp;
	vector<ll> u, s;
	u.resize(N + 1);
	s.resize(N + 1);
	for (i = 1; i <= N; i++) cin >> u[i];
	for (i = 1; i <= N; i++) cin >> s[i];
	for (i = 1; i <= N; i++) mp[u[i]].push_back(s[i]);
	map<ll, vector<ll>>::iterator it;
	vector<vector<ll>> arr, sum;
	for (it = mp.begin(); it != mp.end(); it++) sort(it->second.begin(), it->second.end(), cmp);
	ll k = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		arr.push_back(vector<ll>());
		arr[k].push_back(0);
		ll a = it->second.size();
		for (i = 0; i < a; i++) arr[k].push_back(it->second[i]);
		k++;
	}
	ll sz = mp.size();
	sum.resize(arr.size());
	for (i = 0; i < sz; i++) {
		sum[i].resize(arr[i].size());
		for (ll j = 1; j < arr[i].size(); j++) {
			sum[i][j] = sum[i][j - 1] + arr[i][j];
		}
	}
	ll ans = 0;
	set<ll> st;
	vector<ll> vvv;
	for (i = 0; i < sz; i++) st.insert(i);
	for (i = 1; i <= N; i++) {
		ans = 0;
		for(auto j:st) {
				ll ind = arr[j].size();
				ind--;
				ind /= i;
				ind *= i;
				ans += sum[j][ind];
				if (ind == 0) vvv.push_back(j);
		}
		for (auto a : vvv) st.erase(a);
		vvv.clear();
		cout << ans << ln;
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}