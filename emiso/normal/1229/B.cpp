#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007LL

ll n, ans, h[100010], pai[100010][20], x[100010], g[100010][20];
vector<int> adj[100010];

ll gcd(ll a, ll b) {
    if(!a) return b;
    if(!b) return a;
    return __gcd(a, b);
}

void dfs(int no, int paie = -1) {
    for(int v : adj[no]) {
        if(v == paie) continue;
        h[v] = h[no] + 1;
        pai[v][0] = no;
        g[v][0] = gcd(x[v], x[no]);
        dfs(v, no);
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }

    for(int i = 2; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pai[1][0] = 1;
    g[1][0] = x[1];
    h[1] = 1;

    dfs(1);
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= n; i++) {
            pai[i][j] = pai[pai[i][j-1]][j-1];
            g[i][j] = gcd(g[i][j-1], g[pai[i][j-1]][j-1]);
        }
    }

    for(int i = 1; i <= n; i++) {
        ll tmp = x[i], j = i;
        while(1) {
            tmp = gcd(tmp, x[j]);
            int k = j;

            for(int b = 19; b >= 0; b--)
                if(gcd(tmp, g[j][b]) == tmp)
                    j = pai[j][b];

            ans += (h[k] - h[j] + 1LL) * tmp;
            ans %= MOD;

            if(j == 1) break;
            else j = pai[j][0]; /// ???
        }
    }

    printf("%lld\n", ans);
    return 0;
}