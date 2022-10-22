#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
const int S = 200;
const int M = N*S + N + 7;
int vcnt[M];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;

	int n = s.size();
	vector<int> idx;
	int pre[n+1];
	pre[0] = 0;
	for(int i=0; i<n; i++) {
		pre[i+1] = pre[i] + (s[i] == '1');
		if(s[i] == '1') idx.push_back(i+1);
	}
	idx.push_back(n+1);

	ll ans = 0;

	// small
	for(int k=1; k<=S; k++) {
		for(int i=0; i<=n; i++) {
			int cur = i - k*pre[i] + k*n;
			vcnt[cur]++;
		}
		for(int i=0; i<=n; i++) {
			int cur = i - k*pre[i] + k*n;
			ans += (ll) vcnt[cur] * (vcnt[cur]-1) / 2;
			vcnt[cur] = 0;
		}
	}

	// large
	for(int i=1; i<=n; i++) {
		auto it = lower_bound(begin(idx), end(idx), i);
		for(int cnt=1; next(it) != end(idx) && n > S*cnt; cnt++, it++) {
			int lb = *it - i + 1;
			int rb = *next(it) - i;
			lb = max(S, (lb-1) / cnt);
			rb = (rb) / cnt;
			ans += max(0, rb - lb);
		}
	}

	// answer
	cout << ans << nl;

	return 0;
}