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
const int MX = 100001; 

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

inline bool up(pair<ll,ll> p) {
    return p.s > 1e-9 || (p.s == 0 && p.f > 0);
}

void solve() {
    int N; cin >> N;
    pl P[N];
    int A[N];
    F0R(i, N) cin >> P[i].f >> P[i].s >> A[i];
    F0R(i, N) A[i]--;
    int p = -1;
    F0R(i, N) {
        if (A[i] != i) {
            if (p == -1 || P[i] < P[p]) p = i;
        }
    }
    if (p == -1) {
        cout << 0 << nl; return;
    }

    pair<ll,ll> C = P[p];
    F0R(i, N) {
        P[i].f -= C.f;
        P[i].s -= C.s;
    }

    vector<pair<pl, int>> pts;
    F0R(i, N) if (i != p) pts.pb({P[i], i});
    sort(all(pts), [] (pair<pl, int> a, pair<pl, int> b) {
            return up(a.f) == up(b.f) ? a.f.f * b.f.s > a.f.s * b.f.f : up(a.f) < up(b.f);
            });
    dbg(pts);
    vpi res;
    F0R(i, sz(pts)-1) {
        int v = pts[i].s;
        int nxt = pts[(i+1)%sz(pts)].s;
        int cur = v;
        bool fl = true;
        while (true) {
            cur = A[cur];
            if (cur == nxt) {
                fl = false;
            }
            if (cur == v) break;
        }
        if (fl) {
            res.pb({v, nxt});
            swap(A[v], A[nxt]);
        }
    }

    while (A[p] != p) {
        res.pb({p, A[p]});
        swap(A[p], A[A[p]]);
    }

    cout << sz(res) << nl;
    trav(a, res) cout << a.f+1 << " " << a.s+1 << nl;


}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}