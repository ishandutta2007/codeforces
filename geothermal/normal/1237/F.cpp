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
const int MX = 5401; //check the limits, dummy

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

ll modInv(ll base) {
	return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}


ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

ll* facs = new ll[MX];
ll* facInvs = new ll[MX];

ll choose(ll a, ll b) {
	if (b > a) return 0;
    ll cur = facs[a];
    cur = mul(cur, facInvs[b]);
    cur = mul(cur, facInvs[a-b]);
    return cur;
}

void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i) % MOD;
		facInvs[i] = modInv(facs[i]);
	}
	facInvs[0] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	initFacs();
	
	int N, M, K; cin >> N >> M >> K;
	
	bool vN[N], vM[M]; F0R(i, N) vN[i] = true; 
	F0R(i, M) vM[i] = true;
	F0R(i, K) {
		int A, B, C, D; cin >> A >> B >> C >> D;
		A--; B--; C--; D--;
		vN[A] = false;
		vN[C] = false;
		vM[B] = false;
		vM[D] = false;
	}
	
	int mN = 0, mM = 0;
	F0R(i, N) if (vN[i]) mN++;
	F0R(i, M) if (vM[i]) mM++;
	
	int mx = min(N, M);
	
	ll cN[N+1][N+1];
	F0R(i, N+1) F0R(j, N+1) cN[i][j] = 0;

	cN[0][0] = 1;
	F0R(i, N) {
		F0R(j, N) {
			cN[i+1][j] += cN[i][j]; cN[i+1][j] %= MOD;
			if (i+1 < N && vN[i] && vN[i+1]) { cN[i+2][j+1] += cN[i][j]; cN[i+2][j+1] %= MOD; }
		}
	}
	
	ll cM[M+1][M+1];
	F0R(i, M+1) F0R(j, M+1) cM[i][j] = 0;
	
	cM[0][0] = 1;
	F0R(i, M) {
		F0R(j, M) {
			cM[i+1][j] += cM[i][j]; cM[i+1][j] %= MOD;
			if (i+1 < M && vM[i] && vM[i+1]) { cM[i+2][j+1] += cM[i][j]; cM[i+2][j+1] %= MOD; }
		}
	}
	
	ll ans = 0;
	
	//cout << mM << " " << mN << endl;
	
	F0R(i, mx+1) {
		F0R(j, mx+1) {
			ll res = cN[N][i]; 
			ll empN = mN - 2*i;
			ll empM = mM - 2*j;
			if (empN < 0 || empM < 0) continue;
			res *= choose(empM, i);
			res %= MOD;
			res *= cM[M][j];
			res %= MOD;
			res *= choose(empN, j);
			res %= MOD;
			res *= facs[i]; res %= MOD;
			res *= facs[j]; res %= MOD;
			ans += res; ans %= MOD;
			if (res > 0) {
				//cout << i << " " << j << " " << res << endl;
			}
		}
	}
	
	cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE