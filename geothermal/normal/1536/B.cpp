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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 2000001; 

ll base1[MX], base2[MX];
int base;
ll b1Inv, b2Inv;

ll baseExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = baseExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

struct hsh2  {
    ll p1, p2;

    ll val1, val2;
    vl val1s, val2s;
    vl nums;


    hsh2() {
        p1 = 1000000007;
        p2 = 1000000009;
        val1 = 0;
        val2 = 0;
        val1s.pb(0); val2s.pb(0);
    }


    hsh2(string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        val1 = 0;
        val2 = 0;

        val1s.pb(0); val2s.pb(0);
        F0R(i, sz(S)) {
            push_back(S[i] - 'a');
        }

    }

    void push_back(ll v) {
        val1 *= base;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 += v;
        val2 %= p2;

		val1s.pb(val1);
		val2s.pb(val2);
        nums.pb(v);
    }

    void pop_back() {
        //warning: the extent to which this has been tested is limited lol
        ll v = nums[sz(nums)-1]; nums.pop_back();
        val1s.pop_back(); val2s.pop_back();
        val1 += p1 - v; val1 *= b1Inv;
        val1 %= p1;
        val2 += p2 - v; val2 *= b2Inv; val2 %= p2;
    }

    ll get(int L, int R) {
        ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
        ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
        return A * p2 + B;
    }
};


struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

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
    }

    ll get() {
        return val1 * p2 + val2;
    }
};


void prepHash() {
    base = uniform_int_distribution<int>(1000, MOD-2)(rng);

    base1[0] = 1; base2[0] = 1;
    b1Inv = baseExp(1000000005, 1000000007);
    b2Inv = baseExp(1000000007, 1000000009);
    FOR(i, 1, MX) {
        base1[i] = (base1[i-1] * base) % 1000000007; 
        base2[i] = (base2[i-1] * base) % 1000000009; 
    }
}

hsh H[MX];
string S[MX];
int nxt = 1;

void solve() {
    int N; cin >> N;
    string X; cin >> X;
    hsh2 hc;
    F0R(i, sz(X)) {
        hc.pb(X[i] - 'a' + 1);
    }

    set<ll> hashes;
    F0R(i, sz(X)) {
        FOR(j, i, sz(X)) {
            hashes.ins(hc.get(i,j));
        }
    }

    FOR(i, 1, MX) {
        if (!hashes.count(H[i].get())) {
            cout << S[i] << nl; return;
        }
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    prepHash();
    H[0] = hsh(base, "");
    S[0] = "";
    F0R(i, MX) {
        F0R(j, 26) {
            if (nxt >= MX) continue;
            H[nxt] = H[i]; H[nxt].pb(j+1);
            char C = 'a' + j;
            S[nxt] = S[i]; S[nxt] += C;
            nxt++;
        }
    }
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}