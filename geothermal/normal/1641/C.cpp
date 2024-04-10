#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

const ll SZ = 131072*2;
struct Seg1 {
const ll identity = 0;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return max(A, B);
}

ll combineUpd(ll A, ll B) {
    return min(A, B);
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = 1;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}


ll query(int p, int lo = 0, int hi = SZ-1, int index = 1, ll L = 0, ll R = SZ-1) { //returns first node after p
    push(index, L, R);
    //dbg(p, L, R, index);
    if (lo > R || L > hi || p >= R) return -1;
    bool condition = sum[index];
    if (L == R) {
        //dbg(L, condition);
        return (condition ? L : -1);
    }
    int M = (L+R) / 2;
    push(2*index, L, M);
    if (sum[2*index]) {
        int v = query(p, lo, hi, 2*index, L, M);
        if (v != -1) return v;
    }
    return query(p, lo, hi, 2*index+1, M+1, R); 
}

ll query2(int p, int lo = 0, int hi = SZ-1, int index = 1, ll L = 0, ll R = SZ-1) { //returns last node before p
    push(index, L, R);
    if (lo > R || L > hi || p <= L) return -1;
    bool condition = sum[index];
    if (L == R) {
        return (condition ? L : -1);
    }
    int M = (L+R) / 2;
    push(2*index+1, M+1, R);
    if (sum[2*index+1]) {
        int v = query2(p, lo, hi, 2*index+1, M+1, R);
        if (v != -1) return v;
    }
    return query2(p, lo, hi, 2*index, L, M);
}

ll query3(int p, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (p > R || L > p) return -1;
    if (p<= L && R <= p) return sum[index];

    int M = (L+R) / 2;
    return combine(query3(p, 2*index, L, M), query3(p, 2*index+1, M+1, R));
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

};

struct Seg2 {

set<int> seg[2*SZ]; //segtree implementation by bqi343's Github

int get(int ind, int p) {
    auto it = seg[ind].lb(p);
    if (it == seg[ind].end()) return SZ;
    return *it;
}

ll combine(ll a, ll b) { return min(a, b); }

void update(int p, ll value) {  
    p += SZ;
    while (p > 0) {
        seg[p].ins(value);
        p /= 2;
    }
}

ll query(int l, int r, int p) {  // sum on interval [l, r]
    ll resL = SZ+1, resR = SZ+1; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,get(l++, p));
        if (r&1) resR = combine(get(--r, p),resR);
    }
    return combine(resL,resR);
}
};

Seg1 seg1; 
Seg2 seg2;

void solve() {
    F0R(i, 2*SZ) {
        seg1.sum[i] = 1; seg1.lazy[i] = 1;
    }
    int N, Q; cin >> N >> Q;
    while(Q--) {
        int T; cin >> T;
        if (T == 0) {
            int X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
            //dbg(X, Y, Z);
            if (Z == 0) {
                seg1.update(X, Y, 0);
            } else {
                seg2.update(X, Y);
            }
        } else {
            int X; cin >> X; X--;
            if (seg1.query3(X) == 0) {
                cout << "NO" << nl; continue;
            }
            //dbg(X);
            int R = seg1.query(X);
            int L = seg1.query2(X);
            //dbg(L, R);
            if (R == -1) R = N;
            cout << (seg2.query(L+1, X, X) < R ? "YES" : "N/A") << nl;
        }
    }

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}