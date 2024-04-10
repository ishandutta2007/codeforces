#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1000011; //check the limits, dummy
 
ll base1[MX], base2[MX], b1Inv, b2Inv;
int base;

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    vl val1s, val2s;

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

        val1s.pb(0); val2s.pb(0);
        F0R(i, sz(S)) {
            push_back(S[i] - '0');
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
    }
    
    void pop_back(ll v) {
        val1s.pop_back(); val2s.pop_back();
        val1 += p1 - v; val1 *= b1Inv;
        val1 %= p1;
        val2 += p2 - v; val2 *= b2Inv; val2 %= p2;
    }

    pl get(int L, int R) {
        ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
        ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
        return {A, B};
    }
};

ll modExp(ll base, ll power, ll M) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2, M); cur = cur * cur; cur = cur % M;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % M;
        return cur;
    }
}

void prepHash() {
    base = uniform_int_distribution<int>(1000, MOD-2)(rng);

    base1[0] = 1; base2[0] = 1;
    FOR(i, 1, MX) {
        base1[i] = (base1[i-1] * base) % 1000000007; 
        base2[i] = (base2[i-1] * base) % 1000000009; 
    }
    b1Inv = modExp(base, MOD-2, MOD);
    b2Inv = modExp(base, MOD, MOD+2);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    prepHash();
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S; F0R(i, N) S[i] = '0' + '1' - S[i];
        set<pl> hashes;
        hsh cur(base, S);
        F0R(i, N-K+1) {
            hashes.ins(cur.get(i, i+K-1));
        }
        hsh val;
        string ans; F0R(i, K) ans.pb('0');
        val = hsh(base, ans);
        while (true) {
            if (!hashes.count(val.get(0, K-1))) {
                cout << "YES" << nl; 
                cout << ans << nl; break;
            }
            while (sz(ans) > 0 && ans[sz(ans)-1] == '1') {
                ans.pop_back(); val.pop_back(1);
            }
            if (sz(ans) == 0) {
                cout << "NO" << nl; break;
            }
            ans.pop_back(); val.pop_back(0);
            ans.push_back('1'); val.pb(1);
            while (sz(ans) < K) {
                ans.pb('0'); val.pb(0);
            }
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343