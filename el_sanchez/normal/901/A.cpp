#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

#define FILE_NAME "a"

const int MAXN = (int)2e5 + 100;
const int INF = (int)1e9;

int n, v;
int a[MAXN];
int par[2][MAXN];

bool read() {
    if (scanf("%d", &n) < 1) {
        return 0;
    }
    n++;
    v = 0;
    forn(i, n) {
        scanf("%d", &a[i]);    
        v += a[i];
    }
    
    return 1;
}

int pos;
    
void build(int id) {
    forn(i, v) {
        par[id][i] = -1;
    }
    
    int cur_root = 0;
    par[id][cur_root] = -1;
    int extra = -1;
    int ptr = 1;
    for (int i = 1; i < n; i++) {
        if (i == pos) {
            par[id][ptr] = cur_root;
            extra = ptr;
            ptr++;
            forn(j, a[i] - 1) {
                par[id][ptr++] = cur_root;                
            }
        } else if (i == pos + 1 && id == 0) {
            par[id][ptr] = extra;
            ptr++;
            forn(j, a[i] - 1) {
                par[id][ptr++] = cur_root;                
            }            
        } else {
            forn(j, a[i]) {
                par[id][ptr++] = cur_root;                
            }            
        }
        
        cur_root = ptr - 1;
    }
    
    assert(ptr == v);
}

void solve() {
    pos = -1;
    forn(i, n - 1) {
        if (a[i] > 1 && a[i + 1] > 1) {
            pos = i;   
        }
    }
    
    if (pos == -1) {
        cout << "perfect\n";
        return;   
    }
    
    forn(i, 2) {
        build(i);    
    }
    
    cout << "ambiguous\n";
    forn(id, 2) {
        forn(i, v) {
            printf("%d%c", par[id][i] + 1, " \n"[i == v - 1]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    // freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

#ifdef LOCAL
    eprintf("Time: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif

    return 0;
}