#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
vector<int> g[200005];
queue<int> q;
set<int> se[200005];
int deg[200005];
bool del[200005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
        ++deg[from];
        ++deg[to];
    }
    if (n <= 2) {
        cout << n - 1 << endl;
        return 0;
    }
    forn(i, n) if (int(g[i].size()) == 1) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (deg[v] != 1 || (int)se[v].size() > 1) {
            continue;
        }
        del[v] = true;
        int len = 1;
        if (!se[v].empty()) {
            len += *se[v].begin();
        }
        for (int to : g[v]) if (!del[to]) {
            se[to].insert(len);
            --deg[to];
            if (deg[to] == 1 && (int)se[to].size() <= 1) {
                q.push(to);
            }
        }
    }
    int cnt = 0;
    int sum = 0;
    forn(i, n) if (!del[i]) {
        ++cnt;
        if (int(se[i].size()) > 2) {
            ++cnt;
        }
        for (int x : se[i]) {
            sum += x;
        }
    }
    if (cnt > 1) {
        sum = -1;
    }
    while (sum > 0 && sum % 2 == 0) {
        sum /= 2;
    }
    cout << sum << endl;
    return 0;
}