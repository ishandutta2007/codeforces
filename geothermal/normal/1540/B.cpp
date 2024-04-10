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

void __print(mi X) {
    cout << X.v;
}


mi facs[MX];
mi facInvs[MX];

mi choose(mi _a, mi _b) {
    ll a = (ll) _a, b = (ll) _b;
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    mi cur = facs[a];
    cur = cur * facInvs[b];
    cur = cur * facInvs[a-b];
    return cur;
}

void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i);
	}
    facInvs[MX - 1] = inv(facs[MX-1]);
    F0Rd(i, MX-1) {
        facInvs[i] = facInvs[i+1] * (i+1);
    }
}
void solve() {
    initFacs();
    int N; cin >> N;
    vector<vi> graph(N);
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    mi ans = 0;
    mi half = inv(mi(2));
    mi iv[1001];
    FOR(i, 1, 1001) iv[i] = inv(mi(i));
    mi invPow[1001];
    invPow[0] = 1;
    FOR(i, 1, 1001) invPow[i] = invPow[i-1] * half;
    mi prob[N][N];
    F0R(i, N) {
        F0R(j, N) {
            //ways to get i heads before j tails
            if (i == 0) {
                prob[i][j] = 1;
            } else if (j == 0) {
                prob[i][j] = 0;
            } else {
                F0R(k, j) { //k tails before i'th heads
                    prob[i][j] += choose(i+k-1, k) * invPow[i+k];
                }
            }
        }
    }
    dbg(prob[1][1], prob[1][2]);

    F0R(r, N) {
        int lst[N]; F0R(i, N) lst[i] = -1;
        lst[r] = N;
        int dep[N]; dep[r] = 0;
        vi ord;
        queue<int> q; q.push(r);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            ord.pb(v);
            trav(a, graph[v]) {
                if (lst[a] == -1) {
                    lst[a] = v; q.push(a);
                    dep[a] = dep[v] + 1;
                }
            }
        }
        bool found[N][N]; F0R(i, N) F0R(j, N) found[i][j] = false;
        /*F0R(i, N) {
            int p = i;
            found[p][p] = true;
            while (lst[p] < N) {
                p = lst[p];
                found[i][p] = true;
                found[p][i] = true;
                if (p > i) {
                    ans++;
                }
            }
        }*/

        int L[N][N];
        F0R(i, N) F0R(j, N) L[i][j] = -1;
        queue<pi> q2;
        F0R(i, N) {
            q2.push({i, i});
            L[i][i] = i;
        }
        while (!q2.empty()) {
            int x = q2.front().f, y = q2.front().s; q2.pop();
            trav(a, graph[x]) {
                if (a != lst[x] && L[a][y] == -1) {
                    L[a][y] = L[x][y]; q2.push({a, y});
                }
            }
            trav(b, graph[y]) {
                if (b != lst[y] && L[x][b] == -1) {
                    L[x][b] = L[x][y]; q2.push({x, b});
                }
            }
        }

        F0R(i, N) {
            FOR(j, i+1, N) {
                if (!found[i][j]) {
                    int d1 = dep[i] - dep[L[i][j]], d2 = dep[j] - dep[L[i][j]];
                    //prob[i][j] += d1 * iv[d1+d2];
                    //ans += d1 * iv[d1+d2];
                    ans += prob[d2][d1];
                }
            }
        }

    }
    /*F0R(i, N) {
        FOR(j, i+1, N) {
            dbg(i, j, prob[i][j]);
        }
    }*/

    cout << ans * inv(mi(N)) << nl;


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