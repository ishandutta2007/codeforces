#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 300001; //check the limits, dummy
ll* facs = new ll[MX];

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
	return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i) % MOD;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	initFacs();
	vpi data; F0R(i, N) {
		int A, B; cin >> A >> B; data.pb(mp(A, B));
	}
	
	vi firsts, seconds;
	F0R(i, N) {
		firsts.pb(data[i].f);
		seconds.pb(data[i].s);
	}
	sort(all(firsts)); sort(all(seconds)); sort(all(data));
	
	ll ans = facs[N];
	
	int count = 1;
	ll cur = 1;
	FOR(i, 1, N) {
		if (firsts[i] != firsts[i-1]) {
			cur = mul(cur, facs[count]);
			count = 0;
		}
		count++;
	}
	cur = mul(cur, facs[count]);
	
	ans = sub(ans, cur);
	
	cur = 1;
	count = 1;
	FOR(i, 1, N) {
		if (seconds[i] != seconds[i-1]) {
			cur = mul(cur, facs[count]);
			count = 0;
		}
		count++;
	}
	cur = mul(cur, facs[count]);
	
	ans = sub(ans, cur);
	
	cur = 1;
	count = 1;
	FOR(i, 1, N) {
		if (data[i].s < data[i-1].s) {
			cur = 0;
		}
	}
	
	FOR(i, 1, N) {
		if (data[i] != data[i-1]) {
			cur = mul(cur, facs[count]);
			count = 0;
		}
		count++;
	}
	cur = mul(cur, facs[count]);
	
	ans = add(ans, cur);
	
	cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE