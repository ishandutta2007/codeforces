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
const int MX = 200001; //check the limits, dummy
const int BLK = 450;

int N;
vl A(MX);
int D;

int solve1(int K) {
    vi pos, neg;
    int cur = 0;
    pos.pb(0);
    int ans = 0;
    F0R(i, N) {
        if (A[i] == D) {
            cur++;
        } else if (A[i] == K) {
            cur--;
        }
        if (cur > 0 && sz(pos) <= cur) {
            pos.pb(i+1);
        } else if (cur < 0 && sz(neg) < abs(cur)) {
            neg.pb(i+1);
        }
        if (cur >= 0) {
            ckmax(ans, i-pos[cur]+1);
        } else {
            ckmax(ans, i - neg[-cur - 1] + 1);
        }
    }
    return ans;
}

int solve2(vi &vals) {
    vi pos, neg;
    int cur = 0;
    int p = 0;
    pos.pb(0);
    int ans = 0;
    int lst = -1;
    F0R(i, sz(vals)) {
        if (vals[i] == -1) {
            cur++;
            p++;
            lst = p;
        } else if (vals[i] == -2) {
            cur--; p++;
        } else {
            p += vals[i];
        }

        if (cur > 0 && sz(pos) <= cur) {
            pos.pb(p);
        } else if (cur < 0 && sz(neg) < abs(cur)) {
            neg.pb(p);
        }

        if (cur >= 0) {
            if (pos[cur] < lst) ckmax(ans, p-pos[cur]);
        } else {
            if (neg[-cur-1] < lst) ckmax(ans, p - neg[-cur - 1]);
        }
    }
    return ans;
}

void solve() {

    cin >> N;
    F0R(i, N) cin >> A[i];

    int ans = 0;
    map<int, vi> vals;
    F0R(i, N) {
        vals[A[i]].pb(i);
    }
    D = -1; int hi = -1;
    trav(a, vals) {
        if (ckmax(hi, sz(a.s))) D = a.f;
    }
    vi posD = vals[D];
    trav(a, vals) {
        if (a.f == D) {
            continue;
        } else if (sz(a.s) >= BLK) {
            ckmax(ans, solve1(a.f));
        } else {
            vi use;
            int K = sz(a.s);
            F0R(i, sz(a.s)) {
                int bef = -1;
                if (i > 0) bef = a.s[i-1];
                int aft = N+1;
                if (i < K-1) aft = a.s[i+1];
                auto it = lb(all(posD), a.s[i]);
                int rem = K+1;
                while (it != posD.begin() && (it == posD.end() || *it > bef) && rem) {
                    it--; rem--;
                }
                while (it != posD.end() && *it < a.s[i]) {
                    if (sz(use) == 0 || *it > use[sz(use)-1]) use.pb(*it);
                    it++;
                }
                use.pb(a.s[i]);
                it = lb(all(posD), a.s[i]);
                rem = K+1;
                while (it != posD.end() && *it < aft && rem) {
                    rem--;
                    use.pb(*it);
                    it++;
                }
            }

            vi vals;
            vals.pb(use[0] - 0);
            if (A[use[0]] == D) {
                vals.pb(-1);
            } else {
                vals.pb(-2);
            }
            FOR(i, 1, sz(use)) {
                vals.pb(use[i] - use[i-1] - 1);
                if (A[use[i]] == D) {
                    vals.pb(-1);
                } else vals.pb(-2);
            }
            vals.pb(N-1-use[sz(use)-1]);
            ckmax(ans, solve2(vals));
            /*if (a.f == 6) {
                trav(a, use) {
                    cout << a << " ";
                }
                cout << nl;
            }*/
        }
    }

    cout << ans << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343