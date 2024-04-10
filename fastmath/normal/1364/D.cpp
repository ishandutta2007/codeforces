#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e5 + 7;
int n, m, k;
vector <int> g[N];

int h[N];

int par[N];
int down = -1, up = -1;

bool used[N];
void dfs1(int u, int p) {
    par[u] = p;
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            /*
            #ifdef HOME
            cout << u << "->" << v << endl;
            #endif    
            */
            h[v] = h[u] + 1;
            dfs1(v, u);
        }   
        else if (h[u] > h[v] && v != p) {
            if (down == -1 || (h[u] < h[down])) {
                down = u;
                up = v;
            }   
        }   
    }           
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   

    h[1] = 1;
    dfs1(1, 1);
    /*
    #ifdef HOME
    cout << down << ' ' << up << endl;
    #endif
    */
    if (down != -1 && h[down] <= k) {
        cout << 2 << endl;
        vector <int> cyc;
        int u = down;
        while (u != up) {
            cyc.app(u);
            u = par[u];
        }   
        cyc.app(up);


        cout << cyc.size() << endl;
        for (auto e : cyc)
            cout << e << ' ';
        cout << endl;
    }   
    else {
        cout << 1 << endl;

        vector <int> a[2];
        for (int i = 1; i <= n; ++i) {
            if (down == -1 || h[i] < h[down]) {
                a[h[i]&1].app(i);                                
            }   
        }   

        int want = (k+1)/2;
        for (int t = 0; t < 2; ++t) {
            if (a[t].size() >= want) {

                for (int i = 0; i < want; ++i)
                    cout << a[t][i] << ' ';
                cout << endl;
                exit(0);                    

            }   
        }   

        cout << "LMAO" << endl;
        exit(1);
    }   
}