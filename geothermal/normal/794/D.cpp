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
const int MX = 100001; //check the limits, dummy
 
int base;

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


    hsh(ll b) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
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

    pl get() {
        return {val1, val2};
    }
};

void prepHash() {
   base = uniform_int_distribution<int>(1000, MOD-2)(rng);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    prepHash();

    int N, M; cin >> N >> M;
    vector<set<int> > g1(N);
    F0R(i, N) g1[i].ins(i);
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        g1[A].ins(B); g1[B].ins(A);
    }

    map<pl, int> hashes;
    int H[N];
    F0R(i, N) {
        hsh cur(base);
        trav(a, g1[i]) cur.pb(a);
        pl curHash = cur.get();
        if (!hashes.count(curHash)) {
            hashes[curHash] = sz(hashes);
        }
        H[i] = hashes[curHash];
    }

    if (sz(hashes) == 1) {
        cout << "YES" << nl;
        F0R(i, N) {
            cout << "1 ";
        }
        cout << nl;
        return 0;
    }

    vector<set<int> > g2(sz(hashes));
    F0R(i, N) {
        trav(a, g1[i]) {
            if (H[i] == H[a]) continue;
            g2[H[i]].ins(H[a]);
        }
    }



    int hToVal[sz(hashes)];
    int sta = -1;
    F0R(i, sz(hashes)) {
        if (sz(g2[i]) == 1) {
            sta = i; 
        }
        hToVal[i] = -1;
    }
    if (sta == -1) {
        cout << "NO" << nl; return 0;
    }
    hToVal[sta] = 1;
    F0R(i, sz(hashes) - 1) {
        //get next, update it
        int nxt = -1;
        trav(a, g2[sta]) {
            if (hToVal[a] == -1) {
                if (nxt != -1) {
                    cout << "NO" << nl; return 0;
                }
                nxt = a;
            }
        }
        hToVal[nxt] = hToVal[sta] + 1;
        sta = nxt;
    }
    if (sz(g2[sta]) > 1) {
        cout << "NO" << nl; return 0;
    }

    cout << "YES" << nl;
    F0R(i, N) {
        cout << hToVal[H[i]] << " ";
    }
    cout << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343