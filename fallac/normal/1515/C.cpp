#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 101010
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

void NO() {
	cout << no << ln;
	exit(0);
}

void solve() {
	ll M, N, X;
	cin >> N >> M >> X;
	vector<pair<ll, ll>> v;
	v.resize(N);
	ll i;
	for (i = 0; i < N; i++) cin >> v[i].first, v[i].second = i;
	sort(v.begin(), v.end());
	vector<ll> sum;
	sum.resize(M);
	set<pair<ll, ll>> st;
	for (i = 0; i < M; i++) st.insert({ 0, i });
	vector<ll> ans;
	ans.resize(N);
	set<pair<ll, ll>>::iterator it;
	for (i = N - 1; i >= 0; i--) {
		pair<ll, ll> p = *st.begin();
		st.erase(st.begin());
		ans[v[i].second] = p.second;
		st.insert({ p.first + v[i].first, p.second });
	}
	it = st.end();
	it--;
	ll a, b;
	a = (*st.begin()).first;
	b = (*it).first;
	if (abs(b - a) <= X) {
		cout << yes << ln;
		for (i = 0; i < N; i++) cout << ans[i] + 1 << bb;
		cout << ln;
	}
	else cout << no << ln;
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