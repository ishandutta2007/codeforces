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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 500011; //check the limits, dummy
 
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
mi oneVal[MX];
void precomp() {
    oneVal[0] = 1;
    oneVal[1] = 2;
    FOR(i, 2, MX) {
        oneVal[i] = 8 * oneVal[i-2] + 2 * oneVal[i-1];
    }
}

inline mi val(int ones, int lst) {
    mi res = (lst + 1) * oneVal[ones];
    if (ones > 0) res += (9 - lst) * oneVal[ones-1];
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    string S; cin >> S;
    set<pi> blocks;
    int ls = 0;
    mi ans = 1;
    precomp();
    F0R(i, N) {
        if (S[i] != '1' || i == N-1) {
            blocks.ins({ls, i});
            ans *= val(i - ls, S[i] - '0');
            ls = i+1;
        }
    }

    F0R(i, M) {
        int X, D; cin >> X; X--; cin >> D;

        auto it = blocks.ub({X, N+1});
        it--;
        pi block = *it;
        if (D == 1) {
            if (X == block.s) {
                ans *= inv(val(block.s - block.f, S[block.s] - '0'));
                pi newBlock = block;
                it++;
                if (it != blocks.end()) {
                    pi block2 = *it;
                    newBlock.s = block2.s;
                    ans *= inv(val(block2.s - block2.f, S[block2.s] - '0'));
                    blocks.erase(block2);
                }
                blocks.erase(block);
                blocks.ins(newBlock);
                S[X] = '0' + D;
                ans *= val(newBlock.s - newBlock.f, S[newBlock.s]-'0');
            }
        } else {
            ans *= inv(val(block.s - block.f, S[block.s] - '0'));
            blocks.erase(block);
            pi nb1 = {block.f, X};
            blocks.ins(nb1);
            ans *= val(X-block.f, D);
            if (X != block.s) {
                pi nb2 = {X+1, block.s};
                blocks.ins(nb2);
                ans *= val(block.s-X-1, S[block.s] - '0');
            }
        }

        S[X] = '0' + D;
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343