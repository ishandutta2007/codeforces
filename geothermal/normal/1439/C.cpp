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

const ll identity = 0;
const ll SZ = 131072*2;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return A+B;
}

ll combineUpd(ll A, ll B) {
    return max(A, B);
}

void push(int index, ll L, ll R) {
    if (lazy[index] != 0) sum[index] = lazy[index] * (R-L+1);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}


ll query(ll K, int lo = 0, int hi = SZ-1, int index = 1, ll L = 0, ll R = SZ-1) { //returns first node satisfying con
    push(index, L, R);
    if (lo > R || L > hi) return -1;
    if (L == R) {
        return (sum[index] > K ? L : -1);
    }
    int M = (L+R) / 2;
    push(2*index, L, M);
    if (sum[2*index] > K) {
        return query(K, lo, hi, 2*index, L, M);
    }
    K -= sum[2*index];
    return query(K, lo, hi, 2*index+1, M+1, R);
}

ll getSum(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (L >= lo && hi >= R) {
        return sum[index];
    }
    int M = (L+R)/2;
    return getSum(lo, hi, index*2, L, M) + getSum(lo, hi, 2*index+1, M+1, R);
    
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}
void solve() {

    int N, Q; cin >> N >> Q;

    map<int, ll> peaks;
    set<pl> p2;
    ll X; cin >> X;
    peaks.ins({0, X});
    p2.ins({X, 0});
    update(0, 0, X);
    FOR(i, 1, N) {
        ll Y; cin >> Y;
        update(i, i, Y);
        peaks.ins({i, Y});
        p2.ins({Y, i});
        X = Y;
    }
    vpi rem;
    trav(a, p2) {
        if (p2.ub(a) != p2.end() && p2.ub(a)->f == a.f) {
            rem.pb(a);
        }
    }
    trav(a, rem) p2.erase(a);
    rem.clear();
    
    trav(a, peaks) {
        if (peaks.ub(a.f) != peaks.end() && peaks.ub(a.f)->s == a.s) {
            rem.pb(a);
        }
    }
    trav(a, rem) peaks.erase(a.f);
    while(Q--) {
        /*trav(a, peaks) {
            cout << a.f << " " << a.s << " A" << nl;
        }
        trav(a, p2) {
            cout << a.f << " " << a.s << " B" << nl;
        }*/
        int T; cin >> T;
        int p; ll K; cin >> p >> K;
        p--;
        if (T == 1) {
            if (peaks.lb(p)->s >= K) continue;
            if (peaks.count(p)) {
                p2.erase({peaks[p], p});
            }
            peaks[p] = K;
            p2.ins({K, p});
            while (peaks.find(p) != peaks.begin()) {
                auto it = peaks.find(p);
                it--;
                if (it->s <= K) {
                    p2.erase({it->s, it->f});
                    peaks.erase(it);
                } else break;
            }
            int bef = 0;
            if (peaks.find(p) != peaks.begin()) {
                bef = (--peaks.find(p))->f + 1;
            }
            update(bef, p, K);
        } else {
            int ans = 0;
            int cnt = 0;
            while (p < N) {
                auto it = p2.lb({K+1, -1});
                int val = 0;
                if (it != p2.end()) val = it->s + 1;
                ckmax(p, val);
                if (p == N) break;
                int nxt = query(K + getSum(0, p-1));
                if (nxt == -1) nxt = N;
                K -= getSum(p, nxt-1);
                ans += nxt - p;
                /*if (p == nxt) {
                    cout << p << " " << val << " " << nxt << " " << K << nl;
                    break;
                }*/
                //cout << p << " " << nxt << endl;
                assert(p != nxt);
                p = nxt;
                cnt++;
            }
            cout << ans << nl;
        }
    }
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