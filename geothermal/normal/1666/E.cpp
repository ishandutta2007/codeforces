#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, v) for (auto &a : v)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';
const int MX = 100010;
int N;
ll A[MX];
ll L;
pl ir[MX];

pl inter(pl A, pl B) {
	return {max(A.f, B.f), min(A.s, B.s)};
}
bool ok(ll lo, ll hi) {
	pl cur = {0, 0};
	ir[0] = cur;
	F0R(i, N) {
		cur = inter({cur.f+lo,cur.s+hi}, {A[i], A[i+1]});
		ir[i+1] = cur;
		if (cur.f > cur.s) return false;
	}
	return cur.f <= L && cur.s >= L;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> N;
	F0R(i, N) cin >> A[i];
	A[N] = L;
	ll lo = 0, hi = 2e9;
	while (lo < hi) {
		ll mid = (lo+hi+1)/2;
		if (ok(mid, 2e9)) {
			lo = mid;
		} else hi = mid-1;
	}

	ll lo2 = lo, hi2 = 2e9;
	while (lo2 < hi2) {
		ll mid = (lo2+hi2)/2;
		if (ok(lo, mid)) {
			hi2 = mid;
		} else {
			lo2 = mid+1;
		}
	}

	ok(lo, lo2);
	ll ans[N+1];
	ans[N] = L;
	F0Rd(i, N) {
		pl cur = inter(ir[i], {ans[i+1] - lo2, ans[i+1] - lo});
		ans[i] = cur.f;
	}
	F0R(i, N) {
		cout << ans[i] << " " << ans[i+1] << nl;
	}
	

}