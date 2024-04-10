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
	ll prev;
	while (l < r) {
		if (r - l == 1) {
			ll ret = query(l, r);
			l = (l + r - ret);
			break;
		}
		else if (r - l == 2) {
			ll r1 = query(l, l + 1);
			ll rr = query(l + 1, l + 2);
			if (r1 == l + 1) {
				if (rr == l + 1) {
					ll r2 = query(l, r);
					l = (2 * l + 2 - r2);
				}
				else {
					break;
				}
			}
			else {
				ll r2 = query(l + 1, l + 2);
				l = (2 * l + 3 - r2);
			}
			break;
		}
		mid = (l + r) / 2;
		prev = query(l, r);
		if (prev > mid) {
			ll ret = query(mid + 1, r);
			if (ret != prev) r = mid;
			else l = mid + 1;
		}
		else {
			ll ret = query(l, mid);
			if (ret != prev) l = mid + 1;
			else r = mid;
		}
	}
	cout << '!' << bb << l << ln;
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