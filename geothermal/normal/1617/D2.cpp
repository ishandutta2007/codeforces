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

int query(int A, int B, int C) {
    cout << "? " << A+1 << " " << B+1 << " " << C+1 << endl;
    int X; cin >> X; return X;
}

void solve() {
    int N; cin >> N;
    int zv, ov;
    zv = -1; ov = -1;
    int val[N/3];
    F0R(i, N/3) {
        val[i] = query(i*3, i*3+1, i*3+2);
    }

    int zp = -1, op = -1;
    F0Rd(i, N/3) {
        if (val[i] == 0) zp = i;
        if (val[i] == 1) op = i;
    }

    vi V(3); 
    int cnt = 0;
    F0R(i, 3) {
        V[i] = query(op*3, op*3+1, zp*3+i);
        cnt += V[i];
    }
    if (cnt == 3) {
        ov = op * 3;
    } else ov = op * 3 + 2;

    cnt = 0;
    F0R(i, 3) {
        V[i] = query(zp*3, zp*3+1, op*3+i);
        cnt += V[i];
    }
    if (cnt == 0) {
        zv = zp * 3;
    } else zv = zp * 3 + 2;

    set<int> zeroes;
    zeroes.ins(zv);
    F0R(i, N/3) {
        if (i == zp || i == op) {
            F0R(j, 3) {
                if (i*3+j != zv && i*3+j != ov) {
                    int X = query(zv, ov, i*3+j);
                    if (X == 0) zeroes.ins(i*3+j);
                }
            }
        } else if (val[i] == 0) {
            int X = query(ov, i*3, i*3+1);
            if (X == 0) {
                zeroes.ins(i*3); zeroes.ins(i*3+1);
                X = query(ov, i*3, i*3+2);
                if (X == 0) {
                    zeroes.ins(i*3+2);
                }
            } else {
                zeroes.ins(i*3+2);
                X = query(ov, i*3, i*3+2);
                if (X == 0) {
                    zeroes.ins(i*3);
                } else zeroes.ins(i*3+1);
            }
        } else {
            int X = query(zv, i*3, i*3+1);
            if (X == 0) {
                X = query(zv, i*3, i*3+2);
                if (X == 0) {
                    zeroes.ins(i*3);
                } else zeroes.ins(i*3+1);
            } else {
                X = query(zv, i*3, i*3+2);
                if (X == 0) {
                    zeroes.ins(i*3+2);
                }
            }
        }
    }


    cout << "! " << sz(zeroes) << " ";
    trav(a, zeroes) {
        cout << a+1 << " ";
    }
    cout << endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}