#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;

int n;
vector<int> g[ms];
int sz[ms];
int incluem[ms];
int contido[ms];
int par[ms];
int ponta1, ponta2;
int tamanhoDoResto;


int dfs(int u, int p = -1) {
    sz[u] = 1;
    par[u] = p;
    for(int v : g[u]) {
        if(v != p) sz[u] += dfs(v, u);
    }
    return sz[u];
}

bool check(int u) {
    int start = u;
    while(!contido[u]) {
        contido[u] = 1;
        u = par[u];
    }
    if(u == ponta1) {
        ponta1 = start;
        return true;
    }
    if(u == ponta2) {
        ponta2 = start;
        return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    // memset(dp, -1, sizeof dp);
    // ans[0] = 0;
    // ans[1] = -1;
    // for(int i = 2; i < ms; i++) {
    //     if(i % 2 == 0) ans[i] = min(-ans[i-2]-2, ans[i-2]);
    //     else ans[i] = max(min(-ans[i-2]-2, ans[i-2]), -ans[i-1]-1);
    //     // for(int j = 0; j < i; j++) {
    //     //     int dif = i-j;
    //     //     if(dif % 2 == 1 && i%2 == 0) continue;
    //     //     int k = -ans[j]-dif;
    //     //     if(k > ans[i]) {
    //     //         cout << i << ' ' << j << ' ' << ans[i] << ' ' << k << endl;
    //     //     }
    //     // }
    //     // cout << i << " = " << ans[i] << endl;
    // }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            g[i].clear();
            sz[i] = 0;
            incluem[i] = 0;
            contido[i] = 0;
        }
        for(int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        incluem[0] = n*(n-1)/2;
        for(int v : g[0]) {
            incluem[0] -= sz[v]*(sz[v]-1)/2;
        }
        contido[0] = 1;
        ponta1 = ponta2 = 0;
        for(int i = 1; i < n; i++) {
            if(contido[i]) incluem[i] = incluem[i-1];
            else {
                if(!check(i)) break;
                if(i == 1) {
                    int inicioResto;
                    for(int v : g[0]) if(contido[v]) inicioResto = v;
                    tamanhoDoResto = n - sz[inicioResto];
                }
                if(ponta2 == 0) incluem[i] = sz[ponta1]*tamanhoDoResto;
                else incluem[i] = sz[ponta1] * sz[ponta2];
            }
        }
        cout << n*(n-1)/2 - incluem[0];
        for(int i = 0; i < n; i++) {
            cout << ' ' << incluem[i] - incluem[i+1];
        }
        cout << '\n';
    }
    return 0;
}