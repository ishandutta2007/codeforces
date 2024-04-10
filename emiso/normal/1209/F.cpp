#include <bits/stdc++.h>

using namespace std;

#define MN 2001010
#define MOD 1000000007

int n, m, fake = MN - 1, ans[MN];
vector<int> adj[MN][10];

int main() {
    scanf("%d %d", &n, &m);
    memset(ans, -1, sizeof ans);

    for(int i = 1; i <= m; i++) {
        int a, b, tmp = i;
        scanf("%d %d", &a, &b);

        vector<int> dig;
        while(tmp) {
            dig.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(dig.begin(), dig.end());

        if(dig.size() == 1) {
            adj[a][dig[0]].push_back(b);
            adj[b][dig[0]].push_back(a);
        } else {
            for(int j = 0; j < 2; j++) {
                adj[a][dig[0]].push_back(fake);
                for(int i = 1; i + 1 < dig.size(); i++) {
                    adj[fake][dig[i]].push_back(fake - 1);
                    fake--;
                }
                adj[fake--][dig.back()].push_back(b);
                swap(a, b);
            }
        }
    }

    queue<vector<int>> nza;
    nza.push({1});
    ans[1] = 0;

    while(!nza.empty()) {
        vector<int> x = nza.front();
        nza.pop();

        for(int d = 0; d <= 9; d++) {
            vector<int> nxt;
            for(int u : x) {
                for(int v : adj[u][d]) {
                    if(ans[v] == -1) {
                        nxt.push_back(v);
                        ans[v] = (10LL * ans[u] + d) % MOD;
                    }
                }
            }
            if(!nxt.empty()) nza.push(nxt);
        }
    }

    for(int i = 2; i <= n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}