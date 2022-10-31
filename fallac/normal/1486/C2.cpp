#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef queue<ll> qq;
typedef priority_queue<ll> pqq;
typedef set<ll> ss;
typedef multiset<ll> ms;
typedef pair<ll, ll> pp;
typedef vector<ll>::iterator vit;
typedef set<ll>::iterator sit;
typedef multiset<ll>::iterator msit;
typedef map<ll, ll>::iterator mit;
#define MAX 2010100
#define MAXC 10
#define MOD 993244853
#define INF 2147483647
#define lll ll, ll
#define at auto
#define last(v) ((v)[(v).size()-1])
#define pb push_back
#define all(v) v.begin(), v.end()
#define abs(x) ((x)>0?(x):-(x))
#define sortv(v) sort(all(v))
#define sortvc(v, cmp) sort(all(v), cmp)
#define ln '\n'
#define yes "YES"
#define no "NO"
#define yn(c) ((c)?yes:no)
#define bb ' '
#define testcase ll T=1
#define ttestcase ll T;cin>>T
ll query(ll l, ll r) {
	cout << '?' << bb << l << bb << r << ln;
	cout.flush();
	ll n;
	cin >> n;
	return n;
}
void solve() {
	ll N;
	cin >> N;
	ll l, r, mid;
	l = 1, r = N;
	ll q = query(1, N);
	mid = N / 2;
	ll mode = 0;
	if (q == 1 || q == N) {
		if (q == 1) mode = 1;
	}
	else {
		ll r1 = query(1, q);
		if (r1 != q) mode = 1;
	}
	if (mode == 0) {
		l = 1, r = q;
		while (l < r) {
			if (r - l == 1) break;
			mid = (l + r) / 2;
			ll res = query(mid, q);
			if (res == q) l = mid;
			else r = mid;
		}
		cout << '!' << bb << l << ln;
	}
	else {
		l = q, r = N;
		while (l < r) {
			if (r - l == 1) break;
			mid = (l + r) / 2;
			ll res = query(q, mid);
			if (res == q) r = mid;
			else l = mid;
		}
		cout << '!' << bb << r << ln;
	}
}
void init() {
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	testcase;
	while (T--)init(), solve();
	return 0;
}