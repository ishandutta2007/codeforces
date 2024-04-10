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
const int MX = 1100001; //check the limits, dummy
 
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


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
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


    hsh(string S, ll b) {
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

    pair<int, pl> get(int L, int R) {
        ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
        ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
        return {R-L+1, {A, B}};
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    prepHash();
    mi pows[MX]; pows[0] = 1; 
    FOR(i, 1, MX) pows[i] = pows[i-1] * 2;
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    string T; cin >> T;
    hsh ogHsh(S, base);
    map<pair<int, pl>, int> cnts;
    F0R(i, sz(S)) {
        FOR(j, i, sz(S)) {
            cnts[ogHsh.get(i, j)]++;
        }
    }
    vl len; len.pb(sz(S));
    F0R(i, N) {
        if (sz(S) > 1010000) break;
        S += T[i]; S += S; S.pop_back();
        len.pb(sz(S));
    }
    mi sum[N+1][26];
    F0R(i, 26) sum[0][i] = 0;
    F0R(i, N) {
        F0R(j, 26) sum[i+1][j] = sum[i][j];
        sum[i+1][T[i] - 'a'] += pows[MX-2-i];
    }

    int num[MX];
    num[0] = 1;
    FOR(i, 1, MX) {
        num[i] = num[i-1];
        while (i > len[num[i]]) {
            num[i]++;
        }
    }

    hsh bigHash(S, base);
    pair<int, pl> fir[MX], lst[MX];
    fir[0] = {0, {0, 0}};
    lst[0] = {0, {0, 0}};
    FOR(i, 1, min(MX, sz(S) + 1)) {
        lst[i] = bigHash.get(0, i-1);
        fir[i] = bigHash.get(sz(S) - i, sz(S) - 1);
    }
    while(Q--) {
        int K; cin >> K;
        string cur; cin >> cur;
        hsh hshCur(cur, base);
        mi ans = pows[K] * cnts[hshCur.get(0, sz(cur) -1)];
        mi curInv = inv(pows[MX-1-K]);
/*        F0R(i, sz(cur) + 1) {
            cout << hshCur.val1s[i] << nl;
        }
        ll test = base; test *= base; test %= MOD;
        cout << (hshCur.val1s[3] - hshCur.val1s[1]*test + ((ll)MOD)*MOD) % MOD << nl; */
        F0R(i, sz(cur)) {
            pair<int, pl> beg = {0, {0, 0}}, aft = {0, {0, 0}};
            if (i != 0) {
                beg = hshCur.get(0, i-1);
            }
            if (i != sz(cur)-1) {
                aft = hshCur.get(i+1, sz(cur) - 1);
            }
/*            if (i == 0) {
                cout << beg.s.f << " " << fir[i].s.f << " " << aft.s.f << " " << lst[sz(cur) - 1 - i].s.f << nl;
            }*/
            if (beg == fir[i] && aft == lst[sz(cur) - 1 - i]) {
//                ans += curInv * sum[K][cur[i] - 'a'];
                mi curVal = sum[K][cur[i] - 'a'];
                int ext = max(i, sz(cur) - i - 1);
                F0R(j, min(sz(len), K)) {
                    if ((len[j] < ext) && T[j] == cur[i]) {
                        curVal -= pows[MX-j-2];
                    }
                }
                ans += curInv * curVal;
            }
        }
        cout << ans << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343