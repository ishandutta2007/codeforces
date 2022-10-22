#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int n;
string t[MAXN];
pair <int, int> to[MAXN];
int curr[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] == "AND" || t[i] == "OR" || t[i] == "XOR") {
            cin >> to[i].first >> to[i].second;
            --to[i].first; --to[i].second;
        }
        else if (t[i] == "NOT") {
            cin >> to[i].first;
            --to[i].first;
        }
        else cin >> curr[i];
    }   
}

bool dp[MAXN];
pair <int, int> ans[MAXN];

void calc(int i) {
    if (t[i] == "IN") {
        dp[i] = curr[i];
    }
    else if (t[i] == "AND") {
        calc(to[i].first);
        calc(to[i].second);
        dp[i] = dp[to[i].first] & dp[to[i].second];
    }   
    else if (t[i] == "OR") {
        calc(to[i].first);
        calc(to[i].second);
        dp[i] = dp[to[i].first] | dp[to[i].second];
    }
    else if (t[i] == "XOR") {
        calc(to[i].first);
        calc(to[i].second);
        dp[i] = dp[to[i].first] ^ dp[to[i].second];
    }
    else if (t[i] == "NOT") {
        calc(to[i].first);
        dp[i] = !dp[to[i].first];
    }
}   

void dfs(int i, pair <int, int> c) {
    ans[i] = c;
    if (t[i] == "AND") {
        if (dp[to[i].first]) dfs(to[i].second, c);
        else dfs(to[i].second, {c.first, c.first});
        if (dp[to[i].second]) dfs(to[i].first, c);
        else dfs(to[i].first, {c.first, c.first});
    }
    else if (t[i] == "OR") {
        if (dp[to[i].first]) dfs(to[i].second, {c.second, c.second});
        else dfs(to[i].second, c);
        if (dp[to[i].second]) dfs(to[i].first, {c.second, c.second});
        else dfs(to[i].first, c);
    }
    else if (t[i] == "XOR") {
        if (dp[to[i].first]) dfs(to[i].second, {c.second, c.first});
        else dfs(to[i].second, {c.first, c.second});
        if (dp[to[i].second]) dfs(to[i].first, {c.second, c.first});
        else dfs(to[i].first, {c.first, c.second});
    }
    else if (t[i] == "NOT") {
        dfs(to[i].first, {c.second, c.first});
    }   
    else return;
}   

void solve() {
    calc(0);
    dfs(0, {0, 1});
}

void print() {
    for (int i = 0; i < n; ++i) {
        if (t[i] == "IN") {
            if (curr[i]) cout << ans[i].first;
            else cout << ans[i].second;
        }
    }
    cout << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}