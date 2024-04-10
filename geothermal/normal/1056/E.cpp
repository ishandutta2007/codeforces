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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000001; //check the limits, dummy


ll baseInv1[MX], baseInv2[MX];

ll modExpTest(ll base, ll power, ll prime) {
        if (power == 0) {
                return 1;
        } else {
                ll cur = modExpTest(base, power / 2, prime); cur = cur * cur; cur = cur % prime;
                if (power % 2 == 1) cur = cur * base;
                cur = cur % prime;
                return cur;
        }
}

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

        vl val1s, val2s;

        vl inVal1s, inVal2s;

        ll modExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

    hsh() {
    }


    hsh(ll b, string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
                val1s.pb(0); val2s.pb(0);
        F0R(i, sz(S)) {
            push_back(S[i] - 'a');
        }

    }

    void push_back(ll v) {
        val1 *= base;
        val1 %= p1;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 %= p2;
        val2 += v;
        val2 %= p2;

                val1s.pb(val1);
                val2s.pb(val2);
        //inVal1s.pb(modExp(val1, p1-2));
                //inVal2s.pb(modExp(val2, p2-2));
    }


        pl get(int L, int R) {
            ll A = (val1s[R+1] - (val1s[L] * baseInv1[R-L+1]) % p1 + p1) % p1;
            ll B = (val2s[R+1] - (val2s[L] * baseInv2[R-L+1]) % p2 + p2) % p2;
            return {A, B};
        }



};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
    
    int base = uniform_int_distribution<int>(1000, MOD-2)(rng);
	ll invBase1 = base;
    ll invBase2 = base;
    baseInv1[0] = 1; baseInv2[0] = 1;
    FOR(i, 1, MX) {
        baseInv1[i] = baseInv1[i-1] * invBase1; baseInv1[i] %= MOD;
        baseInv2[i] = baseInv2[i-1] * invBase2; baseInv2[i] %= (MOD+2);
	}
	
	string S; cin >> S;
	string T; cin >> T;
	int N = sz(T), M = sz(S);
	
	ll count[2]; count[0] = 0; count[1] = 0;
	F0R(i, M) {
		count[S[i] - '0']++;
	}
	
	vi solutions;
	FOR(i, 1, N) {
		if (count[0] * i < (ll) N && (ll) (N - count[0] * i) % count[1] == 0) {
			solutions.pb(i);
		}
	}
	
	hsh hash(base, T);
	
	int ans = 0;
	F0R(i, sz(solutions)) {
		int A = solutions[i];
		int B = N - A * count[0]; B /= count[1];
		int cur = 0;
		pl vals[2];
		vals[0] = {-1, -1};
		vals[1] = {-1, -1};
		
		F0R(j, M) {
			int nxt = cur+A;
			if (S[j] == '1') nxt = cur+B;
			pl X = hash.get(cur, nxt-1);
			pl blank = {-1, -1};
			if (vals[S[j] - '0'] == blank) {
				vals[S[j] - '0'] = X;
			} else if (vals[S[j] - '0'] != X) {
				goto done;
			}
			cur = nxt;
		}
		
		if (A == B && vals[0] == vals[1]) goto done;
		
		ans++;
		done:;
	}
	
	cout << ans << endl;
	

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE