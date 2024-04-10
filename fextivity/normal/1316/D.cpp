#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

// #define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
pii a[N][N];
bool ck[N][N];
char ans[N][N];
vpii adj[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'L', 'U', 'R', 'D'};

void ff1(int x, int y, int px, int py){
    ck[x][y] = 1;
    For(i, 0, 4){
        int tx = x + dx[i], ty = y + dy[i];
        if (a[tx][ty].fi == px && a[tx][ty].se == py && !ck[tx][ty]){
            ans[tx][ty] = dir[i];
            ff1(tx, ty, px, py);
        }
    }
}

void ff2(int x, int y){
    ck[x][y] = 1;
    For(i, 0, 4){
        int tx = x + dx[i], ty = y + dy[i];
        if (a[tx][ty].fi == -1 && !ck[tx][ty]){
            adj[x][y].pb({tx, ty});
            adj[tx][ty].pb({x, y});
            ff2(tx, ty);
        }
    }
}

void ff3(int x, int y){
    For(i, 0, 4){
        int tx = x + dx[i], ty = y + dy[i];
        if (a[tx][ty].fi == -1 && !ans[tx][ty]){
            ans[tx][ty] = dir[i];
            ff3(tx, ty);
        }
    }
}

char color[N][N];
pii parent[N][N];
pii cycle_start, cycle_end;
vpii cycle;

bool dfs(int u1, int u2){
    color[u1][u2] = 1;
    Fora(v, adj[u1][u2]){
        if (!color[v.fi][v.se]){
            parent[v.fi][v.se] = {u1, u2};
            if (dfs(v.fi, v.se)){
                return 1;
            }
        }
        else if (color[v.fi][v.se] == 1){
            cycle_end = {u1, u2};
            cycle_start = v;
            return 1;
        }
    }
    color[u1][u2] = 2;
    return 0;
}

bool find_cycle(int x, int y){
    cycle_start = {-1, -1};
    cycle.clear();
    dfs(x, y);
    if (cycle_start.fi == -1){
        return 0;
    }
    cycle.pb(cycle_start);
    for (pii v = cycle_end; v != cycle_start; v = parent[v.fi][v.se]){
        cycle.pb(v);
    }
    cycle.pb(cycle_start);
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ForE(i, 1, n){
        ForE(j, 1, n){
            parent[i][j] = {-1, -1};
        }
    }
    cin >> n;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cin >> a[i][j].fi >> a[i][j].se;
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (a[i][j].fi == i && a[i][j].se == j){
                ans[i][j] = 'X';
                ff1(i, j, i, j);
            }
            else if (a[i][j].fi == -1 && !ck[i][j]){
                ff2(i, j);
                if (!find_cycle(i, j)) Ptest("INVALID");
                For(k, 1, cycle.size()){
                    int difx = cycle[k].fi - cycle[k - 1].fi, dify = cycle[k].se - cycle[k - 1].se;
                    if (difx == 0 && dify == 1){
                        ans[cycle[k].fi][cycle[k].se] = 'L';
                    }
                    if (difx == 1 && dify == 0){
                        ans[cycle[k].fi][cycle[k].se] = 'U';
                    }
                    if (difx == 0 && dify == -1){
                        ans[cycle[k].fi][cycle[k].se] = 'R';
                    }
                    if (difx == -1 && dify == 0){
                        ans[cycle[k].fi][cycle[k].se] = 'D';
                    }
                }
                For(k, 1, cycle.size()){
                    ff3(cycle[k].fi, cycle[k].se);
                }
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (!ans[i][j]) Ptest("INVALID");
        }
    }
    cout << "VALID" << endl;
    ForE(i, 1, n){
        ForE(j, 1, n){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/