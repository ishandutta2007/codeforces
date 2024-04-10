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
void solve() {
	ll N;
	cin >> N;
	ll i, a, p, sum;
	sum = 0;
	bool c = 1;
	for (i = 1; i <= N; i++) {
		cin >> a;
		sum += a;
		if (sum * 2 < i * (i - 1)) c = false;
	}
	cout << yn(c) << ln;
}
void init() {
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	ttestcase;
	while (T--)init(), solve();
	return 0;
}