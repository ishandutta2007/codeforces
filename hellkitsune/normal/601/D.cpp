#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Trie {
    vector<map<int, int> > nx;
    int st;
};

int n, c[300000];
char s[300005];
vector<int> g[300000];
int dif[300000];
Trie *t[300000];

queue<PII> q;
void mergeTries(Trie &t1, Trie &t2) {
    q.push(mp(t1.st, t2.st));
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (auto x : t2.nx[v]) {
            auto it = t1.nx[u].find(x.first);
            int nu;
            if (it == t1.nx[u].end()) {
                nu = t1.nx[u][x.first] = (int)t1.nx.size();
                t1.nx.resize(t1.nx.size() + 1);
            } else {
                nu = it->second;
            }
            q.push(mp(nu, x.second));
        }
    }
}

void dfs(int v, int p) {
    t[v] = NULL;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        if (t[v] == NULL) {
            t[v] = t[to];
        } else {
            if (t[v]->nx.size() < t[to]->nx.size()) {
                swap(t[v], t[to]);
            }
            mergeTries(*t[v], *t[to]);
        }
    }
    if (t[v] == NULL) {
        t[v] = new Trie();
        t[v]->st = 0;
        t[v]->nx.resize(2);
        t[v]->nx[0][s[v] - 'a'] = 1;
        dif[v] = 1;
    } else {
        int pre = t[v]->st;
        t[v]->st = (int)t[v]->nx.size();
        t[v]->nx.resize(t[v]->st + 1);
        t[v]->nx[t[v]->st][s[v] - 'a'] = pre;
        dif[v] = t[v]->st;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", c + i);
    scanf("%s", s);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    int mx = 0;
    REP(i, n) mx = max(mx, dif[i] + c[i]);
    int cnt = 0;
    REP(i, n) if (dif[i] + c[i] == mx) ++cnt;
    //REP(i, n) cout << dif[i] << endl;
    printf("%d %d\n", mx, cnt);
    return 0;
}