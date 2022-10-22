#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 81, INF = 2e9 + 7;

int n, k;
int g[N][N];
vector <int> mem[N][N];

bool used[N];
vector <int> cur;

int ans = INF;

void gen() {
    if (cur.size() == k / 2) {
        for (int e : cur)
            used[e] = 1;
        int nn = 0;
        for (int i = 0; i < k / 2; ++i) {
            int u = cur[i];
            int v;
            if (i == k / 2 - 1)
                v = 0;
            else
                v = cur[i + 1];

            bool f = 0;
            for (int e : mem[u][v]) 
                if (!used[e]) {
                    nn += g[u][e] + g[e][v];
                    f = 1;
                    break;
                }   
            if (!f) {
                for (int e : cur)
                    used[e] = 0;
                return;
            }
        }   
        for (int e : cur)
            used[e] = 0;
        ans = min(ans, nn);
        return;
    }   
    for (int u = 0; u < n; ++u) {
        cur.app(u);
        gen();
        cur.pop_back();
    }   
}   

int A = -1, B = -1;
int get(int u) {
    return g[A][u] + g[u][B];
}   
bool comp(int u, int v) {
    return get(u) < get(v);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    }   
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            for (int k = 0; k < n; ++k) 
                if (k != u && k != v)
                    mem[u][v].app(k);
            A = u;
            B = v;
            sort(all(mem[u][v]), comp);
        }   
    }   
    cur.app(0);
    gen();
    cout << ans << endl;
}