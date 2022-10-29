#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = (int)1e9;
const int MAXN = 300500;

int n, m;
int C, c[MAXN];
vi g[MAXN], s[MAXN];
set<int> used;
int ptr;

void dfs(int v, int pv) {
    used.clear();
    for (auto ms: s[v]) {
        if (c[ms] != -1) {
            used.insert(c[ms]);
        }
    }
    
    int ptr = 0;
    for (int i = 0; i < (int)s[v].size(); ) {
        if (c[s[v][i]] != -1) {
            i++;
            continue;
        }
        assert(ptr < C);
        if (used.find(ptr) != used.end()) {
            ptr++;
            continue;
        }
        c[s[v][i]] = ptr;
        ptr++;
    }
    
    for (auto w: g[v]) {
        if (w != pv) {
            dfs(w, v);   
        }
    }
}

int main() {

    cin >> n >> m;
    forn(i, n) {
        int k;
        scanf("%d", &k);
        s[i].resize(k);
        forn(j, k) {
            scanf("%d", &s[i][j]);   
            s[i][j]--;
        }
    }

    forn(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    C = 1;
    forn(v, n) {
        C = max(C, (int)s[v].size());    
    }
    forn(v, m) {
        c[v] = -1;
    }
    
    dfs(0, -1);
    
    forn(v, m) {
        if (c[v] == -1) {
            c[v] = 0;
        }
    }
    
    cout << C << '\n';
    forn(v, m) {
        printf("%d%c", c[v] + 1, " \n"[v == m - 1]);   
    }
    
    return 0;
}