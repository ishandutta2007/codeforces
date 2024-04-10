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
#define b ' '
ll arr[MAX], arr2[MAX];
void solve() {
	ll N;
	cin >> N;
	ll sq;
	sq = 2 * N - 1;
	ll a = (ll)floor(sqrt(sq));
	cout << (a + 1) / 2 - 1 << ln;
}
void init() {
	ll i;
	for (i = 1; i <= 200; i++) arr[i] = arr2[i] = 0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	init();
	ll T;
	cin >> T;
	while (T-- > 0)init(),solve();
	return 0;
}