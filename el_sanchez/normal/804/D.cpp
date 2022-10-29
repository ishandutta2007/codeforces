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
const int MAXN = 100500;
const int C = 2154;

int n, m, q;
vi g[MAXN];
int ptr, id[MAXN], h[MAXN], high;
int sz[MAXN], diam[2][MAXN], dist[2][MAXN], maxH[MAXN];
int idf[MAXN];
vi comp[MAXN];
int hcnt[MAXN];
vector<int> c[MAXN];
vector<ll> s[MAXN];
vi BIG;
ll prec[111][111];

void dfs(int v, int pv) {
    id[v] = ptr;
    sz[ptr]++;
    comp[ptr].pb(v);

    for (auto w: g[v]) {
        if (w != pv) {
            dfs(w, v);        
        }
    }
}

void dfs2(int v, int pv, int H) {
    h[v] = H;
    if (h[high] < h[v]) {
        high = v;
    }
    
    for (auto w: g[v]) {
        if (w != pv) {
            dfs2(w, v, H + 1);        
        }
    }
}

void dfs3(int v, int pv, int id, int H) {
    dist[id][v] = H;
    for (auto w: g[v]) {
        if (w != pv) {
            dfs3(w, v, id, H + 1);        
        }       
    }
}

ll calc(int a, int b) {
    int D = max(dist[0][diam[1][a]], dist[0][diam[1][b]]);
    ll sum = 0;
    
    //cout << D << '\n';

    //>D
    for (auto v: comp[a]) {
        //cout << maxH[v] << ' ' << c[b][D - maxH[v]] << ' ' << s[b][D - maxH[v]] << '\n';
        sum += 1ll * (maxH[v] + 1) * c[b][D - maxH[v]] + s[b][D - maxH[v]];
        //cout << "SUM: " << sum << '\n'; 
    }
    
    //<=D
    for (auto v: comp[a]) {
        //assert(sz[b] == c[b][0]);
        //cout << sz[b] - c[b][D - maxH[v]] << '\n';
        sum += 1ll * D * max(0, sz[b] - c[b][D - maxH[v]]);
        //cout << "SUM: " << sum << '\n'; 
    }

    return sum;
}

int main() {

    cin >> n >> m >> q;
    forn(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    memset(id, -1, sizeof(id));
    ptr = 0;
    forn(i, n) {
        if (id[i] == -1) {
            h[i] = 0;
            high = i;
            dfs(i, -1);    
            
            diam[1][ptr] = i;
            forn(j, 3) {
                diam[0][ptr] = diam[1][ptr];
                high = diam[0][ptr];
                dfs2(diam[0][ptr], -1, 0);
                diam[1][ptr] = high;            
            }

            forn(j, 2) {
                dfs3(diam[j][ptr], -1, j, 0);    
            }
            
            if (sz[ptr] >= C) {
                idf[ptr] = (int)BIG.size();
                BIG.pb(ptr);
            }
            
            int idc = id[i];
            for (int j = 0; j <= sz[idc]; j++) {
                hcnt[j] = 0;   
            }

            for (auto v: comp[idc]) {
                maxH[v] = max(dist[0][v], dist[1][v]);   
                hcnt[maxH[v]]++;
            }
            
            c[idc].resize(sz[idc] + 1, 0);
            s[idc].resize(sz[idc] + 1, 0);
            
            for (int j = sz[idc] - 1; j >= 0; j--) {
                c[idc][j] = c[idc][j + 1] + hcnt[j];
                s[idc][j] = s[idc][j + 1] + 1ll * hcnt[j] * j;
            }
            assert(c[idc][0] == sz[idc]);
            
            ptr++;
        }
    }
    
    forn(i, BIG.size()) {
        forn(j, BIG.size()) {
            prec[i][j] = calc(BIG[i], BIG[j]);
        }
    }
/*    
    forn(i, ptr) {
        cout << i << ' ' << sz[i] << ":\n";
        for (auto v: comp[i]) {
            cout << "(" << v << ", " << maxH[v] << ")\n";            
        }
        forn(j, sz[i] + 1) 
            cout << c[i][j] << " \n"[j == sz[i]];
        forn(j, sz[i] + 1) 
            cout << s[i][j] << " \n"[j == sz[i]];
           
    }
*/        
    forn(i, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        a--, b--;
        a = id[a];
        b = id[b];
        
        //cout << a << ' ' << b << ":\n";
        
        if (a == b) {
            printf("-1\n");
        } else {
            if (sz[a] > sz[b]) {
                swap(a, b);
            }
            
            ld ans;
            if (sz[a] < C) {
                ans = calc(a, b);
            } else {
                ans = prec[idf[a]][idf[b]];
            }

            ans /= sz[a];
            ans /= sz[b];
            printf("%.10f\n", ans);                
        }
    }
    
    return 0;
}