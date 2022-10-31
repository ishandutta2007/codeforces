/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll A[MAX];
ll B[MAX];

ll getn(set<ll>& st, ll a) {
	auto it = st.lower_bound(a);
	if (it == st.end()) return *st.rbegin();
	if (*it == a) return a;
	ll x = *it;
	if (it == st.begin()) return x;
	else it--;
	ll y = *it;
	if (abs(x - a) > abs(y - a)) return y;
	else return x;
}

void solve() {
	int N;
	cin >> N;
	int i;
	set<ll> sta, stb;
	for (i = 1; i <= N; i++) cin >> A[i], sta.insert(A[i]);
	for (i = 1; i <= N; i++) cin >> B[i], stb.insert(B[i]);
	ll ans = 10101010100;
	ans = abs(A[1] - B[1]) + abs(A[N] - B[N]);
	ans = min(abs(A[1] - B[N]) + abs(A[N] - B[1]), ans);
	ans = min(ans, abs(A[1] - B[1]) + abs(getn(sta, B[N]) - B[N]) + abs(getn(stb, A[N]) - A[N]));
	ans = min(ans, abs(A[N] - B[N]) + abs(getn(sta, B[1]) - B[1]) + abs(getn(stb, A[1]) - A[1]));
	ans = min(ans, abs(getn(sta, B[N]) - B[N]) + abs(getn(stb, A[N]) - A[N]) + abs(getn(sta, B[1]) - B[1]) + abs(getn(stb, A[1]) - A[1]));
	reverse(B + 1, B + N + 1);
	ans = min(ans, abs(A[1] - B[1]) + abs(getn(sta, B[N]) - B[N]) + abs(getn(stb, A[N]) - A[N]));
	ans = min(ans, abs(A[N] - B[N]) + abs(getn(sta, B[1]) - B[1]) + abs(getn(stb, A[1]) - A[1]));
	ans = min(ans, abs(getn(sta, B[N]) - B[N]) + abs(getn(stb, A[N]) - A[N]) + abs(getn(sta, B[1]) - B[1]) + abs(getn(stb, A[1]) - A[1]));
	cout << ans << ln;
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