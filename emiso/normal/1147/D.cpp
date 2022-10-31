#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;
typedef long long ll;

ll ans, n, vis[2010];
char s[1010];
vector<int> adj[2010][2];

void clean() {
    for(int i = 0; i < 2010; i++) {
        adj[i][0].clear();
        adj[i][1].clear();
        vis[i] = -1;
    }
}

void add(int a, int b, int c) {
    adj[a][c].push_back(b);
    adj[b][c].push_back(a);
}

int dfs(int no, int cor = 0) {
    if(vis[no] == -1) vis[no] = cor;
    else if(vis[no] != cor) return 0;
    else return 1;

    int flag = 1;
    for(int c = 0; c <= 1; c++)
        for(int v : adj[no][c])
            flag &= dfs(v, cor ^ c);

    return flag;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    reverse(s, s + n);

    for(int k = 1; k < n; k++) {
        clean();
        for(int l = 0, r = n-1; l < r; l++, r--) add(l, r, 0);
        for(int l = 0, r = k-1; l < r; l++, r--) add(1000+l, 1000+r, 0);

        add(1000+k-1, 2000, 1);
        for(int i = 0; i < n; i++) {
            if(s[i] != '?') add(i, 1000+i, s[i]=='1');
            if(i >= k) add(1000+i, 2000, 0);
        }

        ll mult = 1;
        if(dfs(2000) == 0) mult = 0;
        for(int i = 0; mult && i < 2010; i++) {
            if((i < n || (i >= 1000 && i < 1000 + k)) && vis[i] == -1) {
                if(dfs(i) == 0) mult = 0;
                mult = mult * 2LL  % MOD;
            }
        }
        ans += mult;
        if(ans >= MOD) ans -= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}