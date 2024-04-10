#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int cnt, v[N], n, a[N], deg[N], two[N];
vector<int> e[N];
queue <int> Q;

void dfs(int x) {
    cnt++;
    v[x] = 1;
    for (int i = 0; i < e[x].size(); i++) {
        int y = e[x][i];
        if (!v[y]) {
            dfs(y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        e[i].push_back(a[i]);
        e[a[i]].push_back(i);
        deg[i]++;
        deg[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    if (deg[i] == 1) Q.push(i);

    memset(v, 0, sizeof(v));
    int num = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        v[x] = 1;
        num++;
        for (int i = 0; i < e[x].size(); i++) {
            int y = e[x][i];
            if (--deg[y] == 1) {
                Q.push(y);
            }
        }
    }


    two[0] = 1;
    for (int i = 1; i <= n; i++) {
        two[i] = two[i - 1] * 2 % MOD;
    }
    for (int i = 1; i <= n; i++) {
        two[i] -= 2;
        two[i] += MOD;
        two[i] %= MOD;
    }

    long long ans = 1;
    for (int i = 1; i <= n; i++)
    if (!v[i]) {
        cnt = 0;
        dfs(i);
        ans *= two[cnt];
        ans %= MOD;
    }

    for (int i = 0; i < num; i++)
        ans = ans * 2 % MOD;
    cout << ans << endl;
}