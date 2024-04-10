#include <bits/stdc++.h>
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

int sg(int X, int Y) {
    if (X == 0) return abs(Y);
    if (Y == 0) return abs(X);
    return __gcd(abs(X), abs(Y));
}

void solve() {
    int N; cin >> N;
    int cnt[4][4];
    F0R(i, 4) F0R(j, 4) cnt[i][j]=0;
    int X[N], Y[N];
    F0R(i, N) {
        cin >> X[i] >> Y[i];
        cnt[X[i]%4][Y[i]%4]++;
    }
    ll ans = 0;
    F0R(m, 16*16*16) {
        vi vals;
        int cm = m;
        F0R(i, 6) {
            vals.pb(cm%4); cm /= 4;
        }
        if (vals[0]*4+vals[1] > vals[2]*4+vals[3]) continue;
        if (vals[2]*4+vals[3] > vals[4]*4+vals[5]) continue;
        if (abs(vals[0]-vals[2])%2 || abs(vals[1]-vals[3])%2 || abs(vals[2]-vals[4])%2 || abs(vals[3]-vals[5])%2) continue;
        ll cur = 1;
        F0R(i, 3) {
            int cv = cnt[vals[i*2]][vals[i*2+1]];
            F0R(j, i) {
                if (vals[i*2] == vals[j*2] && vals[i*2+1] == vals[j*2+1]) {
                    cv--;
                }
            }
            cur *= cv;
        }
        bool as = (vals[0] == vals[2] && vals[1] == vals[3]), bs = (vals[2] == vals[4] && vals[3] == vals[5]);
        if (as && bs) {
            cur /= 6;
        } else if (as || bs) {
            cur /= 2;
        }

        vi test = {1, 1, 1, 1, 3, 1};

        int V = vals[0] * (vals[3] - vals[5]) + vals[2] * (vals[5] - vals[1]) + vals[4] * (vals[1] - vals[3]);
        /*F0R(i, 3) {
            F0R(j, 3) {
                if (i == j) continue;
                V += vals[i*2] * vals[j*2+1]; 
            }
        }*/
        V = abs(V);
        if (V %2) continue;
        V /= 2; V %= 2;
        F0R(i, 3) {
            FOR(j, i+1, 3) {
                if (i == j) continue;
                V += max((abs(vals[i*2]-vals[j*2])/2)%2, (abs(vals[i*2+1]-vals[j*2+1])/2)%2);
                /*vi test = {0, 0, 2, 0, 2, 2};
                if (vals == test) {
                    dbg(V);
                }*/
            }
        }
        V %= 2;
        if (V % 2 == 0) ans += cur;
    }

    F0R(r, N) {
        int C[4][4][2];
        F0R(i, 4) F0R(j, 4) F0R(k, 2) C[i][j][k] = 0;
        F0R(i, N) {
            if (i == r) continue;
            int K = sg(X[i]-X[r], Y[i]-Y[r]);
            if (K%2==0) continue;
            K %= 4;
            C[X[i]%4][Y[i]%4][K/2]++;
        }

        F0R(m, 4*4*4*4*2*2) {
            vi vals(6);
            int cm = m;
            F0R(i, 6) {
                if (i%3==2) {
                    vals[i] = cm%2; cm /= 2;
                } else {
                    vals[i] = cm%4; cm /= 4;
                }
            }
            if (vals[0]*16+vals[1]*4+vals[2] > vals[3]*16+vals[4]*4+vals[5]) continue;
            if (abs(vals[0]-vals[3])%2 || abs(vals[1]-vals[4])%2) continue;
            //vi test = {2, 1, 0, 2, 1, 1};
            int cur = 1;
            F0R(i, 2) {
                int cv = C[vals[i*3]][vals[i*3+1]][vals[i*3+2]];
                if (i == 1 && vals[0]==vals[3]&&vals[1]==vals[4]&&vals[2]==vals[5]) cv--;
                cur *= cv;
            }
            if (vals[0]==vals[3]&&vals[1]==vals[4]&&vals[2]==vals[5]) cur /= 2;
            /*if (r == 2 && cur) {
                dbg(vals);
            }*/

            int V = 0;
            /*F0R(i, 2) {
                V += X[r] * vals[i*3+1] + Y[r] * vals[i*3];
                V %= 4;
            }
            V += vals[0] * vals[4] + vals[1] * vals[3];*/
            V = X[r] * (vals[1] - vals[4]) + vals[0] * (vals[4] - Y[r]) + vals[3] * (Y[r] - vals[1]);
            V = abs(V);
            V %= 4;
            /*if (r == 2 && cur) {
                dbg(V);
            }*/
            if (V % 2) continue;
            V /= 2;
            int GT = 0;
            GT += vals[2]*2+1 + vals[5]*2+1;
            GT += 2*max((abs(vals[0]-vals[3])/2)%2, (abs(vals[1]-vals[4])/2)%2);
            if (GT%2) continue;
            V += GT/2;
            if (V%2) continue;
            ans += cur;
        }
    }

    cout << ans << nl;

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