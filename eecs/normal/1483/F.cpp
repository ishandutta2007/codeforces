#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, ans, tot = 1, mark[maxn], L[maxn], mp[maxn], mn[maxn];
int ch[maxn][26], mx[maxn], sec[maxn], fail[maxn], in[maxn], out[maxn];
string s[maxn];
vector<int> G[maxn], pos[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int cur = 1;
        for (char $ : s[i]) {
            int c = $ - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c], pos[i].push_back(cur);
        }
        if (s[i].size() > s[mx[cur]].size()) sec[cur] = mx[cur], mx[cur] = i;
        else if (s[i].size() > s[sec[cur]].size()) sec[cur] = i;
    }
    fill(ch[0], ch[0] + 26, 1);
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(), f = fail[v]; Q.pop();
        if (s[mx[f]].size() > s[mx[v]].size()) sec[v] = mx[v], mx[v] = mx[f];
        else if (s[mx[f]].size() > s[sec[v]].size()) sec[v] = mx[f];
        if (s[sec[f]].size() > s[sec[v]].size()) sec[v] = sec[f];
        for (int c = 0; c < 26; c++) {
            if (ch[v][c]) fail[ch[v][c]] = ch[fail[v]][c], Q.push(ch[v][c]);
            else ch[v][c] = ch[fail[v]][c];
        }
    }
    for (int i = 2; i <= tot; i++) {
        G[fail[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        static int tim = 0;
        in[v] = ++tim;
        for (int u : G[v]) dfs(u);
        out[v] = tim;
    };
    dfs(1);
    for (int i = 1, tim = 0; i <= n; i++) {
        L[s[i].size()] = INT_MAX;
        int cur = 1;
        for (int k = 0; k < s[i].size(); k++) {
            cur = ch[cur][s[i][k] - 'a'];
            int j = mn[k] = mp[k] = mx[cur] == i ? sec[cur] : mx[cur];
            if (!j) L[k] = INT_MAX;
            else L[k] = k + 1 - s[j].size();
        }
        set<int> S1, S2;
        for (int k = s[i].size() - 1; ~k; k--) {
            if (L[k + 1] <= k) S1.insert(in[pos[mn[k + 1]][k - L[k + 1]]]);
            if (L[k + 1] < L[k]) mn[k] = mn[k + 1];
            L[k] = min(L[k], L[k + 1]);
            if (L[k] <= k) S2.insert(in[pos[mn[k]][k - L[k]]]);
        }
        tim++;
        for (int k = 0, j; k < s[i].size(); k++) if (mp[k] && mark[j = mp[k]] ^ tim) {
            auto it = S1.lower_bound(in[pos[j].back()]);
            if (it == S1.end() || *it > out[pos[j].back()]) {
                it = S2.upper_bound(in[pos[j].back()]);
                if (it == S2.end() || *it > out[pos[j].back()]) mark[j] = tim, ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}