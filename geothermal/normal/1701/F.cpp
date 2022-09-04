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


const ll identity = 0;
const int SZ = 131072*2;

ll sumL[2*SZ], sumR[2*SZ], lazyL[2*SZ], lazyR[2*SZ];
ll sumAct[2*SZ], sumVL[2*SZ], sumVR[2*SZ];

ll combine(ll A, ll B) { return A+B; }

void push(int index, ll L, ll R) {
    sumVL[index] = sumVL[index] + (R-L+1) * lazyL[index];
    sumVR[index] = sumVR[index] + (R-L+1) * lazyR[index];

    sumL[index] += lazyL[index] * sumAct[index];
    sumR[index] += lazyR[index] * sumAct[index];

    if (L != R) lazyL[2*index] += lazyL[index], lazyL[2*index+1] += lazyL[index];
    if (L != R) lazyR[2*index] += lazyR[index], lazyR[2*index+1] += lazyR[index];

    lazyL[index] = 0;
    lazyR[index] = 0;
}

void pull(int index) {
    sumL[index] = sumL[2*index] + sumL[2*index+1];
    sumR[index] = sumR[2*index] + sumR[2*index+1];
    sumVL[index] = sumVL[2*index] + sumVL[2*index+1];
    sumVR[index] = sumVR[2*index] + sumVR[2*index+1];
    sumAct[index] = sumAct[2*index] + sumAct[2*index+1];
}

ll queryL(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sumL[index];

    int M = (L+R) / 2;
    return combine(queryL(lo, hi, 2*index, L, M), queryL(lo, hi, 2*index+1, M+1, R));
}

ll queryR(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sumR[index];

    int M = (L+R) / 2;
    return combine(queryR(lo, hi, 2*index, L, M), queryR(lo, hi, 2*index+1, M+1, R));
}

ll queryAct(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sumAct[index];

    int M = (L+R) / 2;
    return queryAct(lo, hi, 2*index, L, M) + queryAct(lo, hi, 2*index+1, M+1, R);
}


void updateL(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazyL[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    updateL(lo, hi, increase, 2*index, L, M); updateL(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

void updateR(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazyR[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    updateR(lo, hi, increase, 2*index, L, M); updateR(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

void setAct(int p, int v, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (p < L || p > R) return;
    if (L == R) {
        sumAct[index] = v;
        sumL[index] = v * sumVL[index];
        sumR[index] = v * sumVR[index];
        return;
    }
    int M = (L+R)/2;
    setAct(p, v, 2*index, L, M); setAct(p, v, 2*index+1, M+1, R);
    pull(index);
    //dbg(p, v, L, R, sumAct[index]);
}

void solve() {
    int Q, D; cin >> Q >> D;
    bool curIn[SZ]; F0R(i, SZ) curIn[i] = false;
    ll ans = 0;
    while(Q--) {
        int X; cin >> X;
        int mul = 1;
        if (curIn[X]) {
            mul = -1; curIn[X] = false;
        } else curIn[X] = true;
        ll V = queryAct(X+1, min(SZ-1, X+D));
        if (mul == -1) ans += V;
        ans += V*(V-1)/2*mul;
        V = queryAct(max(0, X-D), X-1);
        ans += V*(V-1)/2*mul;
        V = queryR(X+1, SZ-1);
        ans += V*mul;
        V = queryL(X+1, SZ-1);
        ans -= V*mul;
        setAct(X, (mul==1?1:0));
        updateR(X+1, min(X+D, SZ-1), mul);
        updateL(max(0, X-D), X-1, mul);
        cout << ans << nl;
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