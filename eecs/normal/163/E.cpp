#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxV = maxn * 10;
int n, K, ecnt, ed[maxn];
int tot = 1, ch[maxV][26], fail[maxV], tid[maxV], c[maxV];
bool vis[maxn];
string str, op[maxn];
struct edge { int to, nxt; } e[maxV];

void add(int p, int v) {
    for (; p <= tot; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> K;
    auto ins = [&](string str) {
        int cur = 1;
        for (char $ : str) {
            int c = $ - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c];
        }
        return cur;
    };
    for (int i = 1; i <= K; i++) {
        cin >> str, ed[i] = ins(str);
    }
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
    }
    fill(ch[0], ch[0] + 26, fail[0] = 1);
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int c = 0; c < 26; c++) {
            if (ch[u][c]) fail[ch[u][c]] = ch[fail[u]][c], Q.push(ch[u][c]);
            else ch[u][c] = ch[fail[u]][c];
        }
    }
    for (int i = 2; i <= tot; i++) {
        e[++ecnt] = (edge){i, c[fail[i]]}, c[fail[i]] = ecnt;
    }
    function<void(int)> dfs = [&](int u) {
        static int tim = 0;
        tid[u] = ++tim, fail[u] = 1;
        for (int i = c[u]; i; i = e[i].nxt) {
            dfs(e[i].to), fail[u] += fail[e[i].to];
        }
    };
    dfs(1);
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= K; i++) {
        add(tid[ed[i]], 1), add(tid[ed[i]] + fail[ed[i]], -1);
        vis[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        str = op[i].substr(1);
        if (op[i][0] == '+') {
            int id = stoi(str);
            if (vis[id]) continue;
            add(tid[ed[id]], 1), add(tid[ed[id]] + fail[ed[id]], -1);
            vis[id] = 1;
        } else if (op[i][0] == '-') {
            int id = stoi(str);
            if (!vis[id]) continue;
            add(tid[ed[id]], -1), add(tid[ed[id]] + fail[ed[id]], 1);
            vis[id] = 0;
        } else {
            int cur = 1;
            long long ans = 0;
            for (char $ : str) {
                cur = ch[cur][$ - 'a'], ans += sum(tid[cur]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}