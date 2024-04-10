#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long

const int INF = 1e16 + 7;
const int MAXN = 4e5 + 7;
const int LG = 23;

int go[MAXN][LG], go1[MAXN][LG];
int dp[MAXN][LG];
int mx[MAXN][LG];
int cost[MAXN];

void add(int u, int parent, int ncost){
    cost[u] = ncost;
    
    go[u][0] = parent;
    mx[u][0] = cost[parent];
    for (int pw = 1; pw < LG; ++pw){
        if (go[u][pw - 1] == -1) {
            for (int i = pw; i < LG; ++i){
                go[u][i] = -1;
            }
            break;
        }
        go[u][pw] = go[go[u][pw - 1]][pw - 1];
        mx[u][pw] = max(mx[u][pw - 1], mx[go[u][pw - 1]][pw - 1]);
    }

    if (cost[u] <= cost[parent]){
        go1[u][0] = parent;
    }
    else {
        int v = parent;
        for (int pw = LG - 1; pw >= 0; --pw){
            if (go[v][pw] == -1) continue;
            if (mx[v][pw] < cost[u]){
                v = go[v][pw];
            }
        }
        go1[u][0] = go[v][0];
    }
    
    for (int pw = 1; pw < LG; ++pw){
        if (go1[u][pw - 1] == -1) {
            for (int i = pw; i < LG; ++i){
                go1[u][i] = -1;
            }
            break;
        }
        go1[u][pw] = go1[go1[u][pw - 1]][pw - 1];
    }

    dp[u][0] = cost[go1[u][0]];
    for (int pw = 1; pw < LG; ++pw){
        if (go1[u][pw - 1] == -1) break;
        dp[u][pw] = dp[u][pw - 1] + dp[go1[u][pw - 1]][pw - 1];
    }
}

int get(int u, int x){
    if (x < cost[u]) return 0;

    x -= cost[u];
    int len = 1;
    for (int pw = LG - 1; pw >= 0; --pw){
        if (go1[u][pw] == -1) continue; 

        if (dp[u][pw] <= x){
            x -= dp[u][pw];
            len += (1 << pw);
            u = go1[u][pw];
        }
    }

    return len;
}

signed main(){
    ios_base::sync_with_stdio(false);

    cost[0] = 0;
    for (int pw = 0; pw < LG; ++pw) mx[0][pw] = -1;
    for (int pw = 0; pw < LG; ++pw) go[0][pw] = go1[0][pw] = -1;

    int q;
    cin >> q;
    int last = 0;
    int cnt = 1;
    for (int i = 0; i < q; ++i){
        int t;
        cin >> t;
        if (t == 1){
            int p, q;
            cin >> p >> q;
            int r = p ^ last;
            int w = q ^ last;
            add(cnt, r - 1, w);
            ++cnt;
        }
        else {
            int p, q;
            cin >> p >> q;

            int r = p ^ last;
            int x = q ^ last;
            
            last = get(r - 1, x);
            cout << last << '\n';
        }
    }

    return 0;
}