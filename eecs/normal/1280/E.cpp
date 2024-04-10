#include <bits/stdc++.h>
using namespace std;

const int maxn = 160010;
int T, r, f[maxn], lnk[1000010], mark[maxn], from[maxn];
long long ans[maxn];
string str;
vector<int> G[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> r;
        getline(cin, str);
        stack<int> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') st.push(i);
            if (str[i] == ')') lnk[st.top()] = i, st.pop();
        }
        int cnt = count(str.begin(), str.end(), '*');
        int tot = cnt, id = 0;
        function<int(int, int)> solve = [&](int l, int r) {
            while (str[l] == ' ') l++;
            while (str[r] == ' ') r--;
            if (l == r) { f[++id] = 1; return id; }
            int k = ++tot;
            mark[k] = 0;
            for (int i = l + 1; i < r; i++) {
                if (str[i] == ' ' || str[i] == 'P') continue;
                if (str[i] == 'S') mark[k] = 1;
                else if (str[i] == '*') G[k].push_back(solve(i, i));
                else G[k].push_back(solve(i, lnk[i])), i = lnk[i];
            }
            if (!mark[k]) {
                f[k] = 0;
                for (int x : G[k]) f[k] += f[x];
            } else {
                f[k] = INT_MAX;
                for (int x : G[k]) if (f[x] < f[k]) f[k] = f[x], from[k] = x;
            }
            return k;
        };
        int rt = solve(0, str.size() - 1);
        function<void(int)> dfs = [&](int v) {
            if (v <= cnt) { ans[v] = 1LL * r * f[rt]; return; }
            if (!mark[v]) for (int x : G[v]) dfs(x);
            else dfs(from[v]);
        };
        fill(ans + 1, ans + cnt + 1, 0), dfs(rt);
        cout << "REVOLTING";
        for (int i = 1; i <= cnt; i++) cout << ' ' << ans[i];
        cout << '\n';
        for (int i = 1; i <= tot; i++) G[i].clear();
    }
    return 0;
}