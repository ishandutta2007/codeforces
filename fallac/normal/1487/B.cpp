#include <bits/stdc++.h>
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
#define MAX 201010
#define MOD 993244853
#define INF 2147483647
#define lll ll, ll
#define at auto
#define pb push_back
#define all(v) v.begin(), v.end()
#define abs(x) ((x)>0?(x):-(x))
#define sortv(v) sort(all(v))
#define sortvc(v, cmp) sort(all(v), cmp)
#define rangeds(it, ds) it=(ds).begin();it!=(ds).end;it++
#define rangei(i, s, f) i=(s);i<=(f);i++
#define ln '\n'
#define yes "YES"
#define no "NO"
void solve() {
	ll N, M;
	cin >> N >> M;
	if (N % 2) {
		ll k = N / 2;
		ll a = (M - 1) / k;
		ll b = M - a - 1;
		a *= 2;
		cout << (a + b) % N + 1 << ln;
	}
	else {
		cout << 1 + (M - 1) % N << ln;
	}
}
void init() { }
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	init();
	ll T;
	cin >> T;
	while (T-- > 0)solve();
	return 0;
}