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
const int MX = 1000001; //check the limits, dummy
 
struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


ll base1[MX], base2[MX];
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
    }

    pl get(int L, int R) {
        if (L > R) {
            return {0, 0};
        }
        if (L == 0) {
            return {val1s[R+1], val2s[R+1]};
        }
        ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
        ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
        return {A, B};
    }
};

void prepHash() {
    base = uniform_int_distribution<int>(1000, MOD-2)(rng);

    base1[0] = 1; base2[0] = 1;
    FOR(i, 1, MX) {
        base1[i] = (base1[i-1] * base) % 1000000007; 
        base2[i] = (base2[i-1] * base) % 1000000009; 
    }
}

typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
int N;
string S[MX];
vector<vi> sind(MX);
hsh H[MX];
pl combine(pl A, pl B, ll num) {
    pl res = {A.f * base1[num] + B.f, A.s * base2[num] + B.s};
    res.f %= MOD;
    res.s %= MOD+2;
    return res;
}

bool ear(int A, int ap, int B, int bp) {
    if (ap == sz(S[A])) ap++;
    if (bp == sz(S[B])) bp++;
    int as = sz(S[A]); if (ap != sz(S[A])+1) as--;
    int bs = sz(S[B]); if (bp != sz(S[B])+1) bs--;
    int lo = 0, hi = min(as, bs); //LCP length binary search
    while (lo < hi) {
        int mid = (lo+hi+1)/2; //get first mid characters
        pl ca, cb;
        if (mid <= ap) {
            ca = H[A].get(0, mid-1);
        } else {
            ca = combine(H[A].get(0, ap - 1), H[A].get(ap+1, mid), mid - ap);
        }

        if (mid <= bp) {
            cb = H[B].get(0, mid-1);
        } else {
            cb = combine(H[B].get(0, bp - 1), H[B].get(bp+1, mid), mid - bp);
        }

        if (ca == cb) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    int ax = lo, bx = lo;
    if (ax >= ap) ax++;
    if (bx >= bp) bx++;
    if (ax == sz(S[A])) return true;
    if (bx == sz(S[B])) return false;
    return S[A][ax] < S[B][bx];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    cin >> N;
    F0R(i, N) cin >> S[i];
    vector<vmi> dp(N);
    prepHash();
    F0R(i, N) H[i] = hsh(base, S[i]);
    F0R(i, N) {
        bool ok[sz(S[i])];
        ok[sz(S[i])-1] = true;
        F0Rd(j, sz(S[i])-1) {
            if (S[i][j] < S[i][j+1]) {
                ok[j] = false;
            } else if (S[i][j] > S[i][j+1]) {
                ok[j] = true;
            } else {
                ok[j] = ok[j+1];
            }
        }
        vi bef, aft;
        F0R(j, sz(S[i])) {
            if (ok[j]) {
                bef.pb(j);
            } else {
                aft.pb(j);
            }
        }
        reverse(all(aft));
        trav(a, bef) sind[i].pb(a);
        sind[i].pb(sz(S[i]));
        trav(a, aft) sind[i].pb(a);
    }

    dp[0] = vmi(sz(S[0])+1, 1);
    F0R(i, N-1) {
        dp[i+1] = vmi(sz(S[i+1])+1);

        mi cur = 0;
        int p = 0;
        F0R(j, sz(S[i+1])+1) {
            while (p <= sz(S[i]) && ear(i, sind[i][p], i+1, sind[i+1][j])) {
                cur += dp[i][p];
                p++;
            }
            dp[i+1][j] = cur;
        }
    }

    mi ans = 0; trav(a, dp[N-1]) ans += a;
    cout << ans << nl;

/*    F0R(i, N) {
        F0R(j, sz(S[i])+1) {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }

    cout << "SIND" << nl;
    F0R(i, N) {
        F0R(j, sz(S[i])+1) {
            cout << sind[i][j] << " ";
        }
    }
    cout << nl;*/
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343