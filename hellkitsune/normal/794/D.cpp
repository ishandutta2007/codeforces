#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef unsigned long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[300000];
mt19937_64 mt(time(0));
LL h[300000], a[300000] = {};
map<LL, int> ma;
int par[300000];
int ans[300000];
int rem = 0, deg[300000] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) {
        h[i] = mt();
    }
    forn(i, n) {
        a[i] = h[i];
        for (int to : g[i]) {
            a[i] ^= h[to];
        }
        auto it = ma.find(a[i]);
        if (it == ma.end()) {
            par[i] = i;
            ma[a[i]] = i;
        } else {
            par[i] = it->second;
        }
    }
    forn(i, n) if (par[i] == i) {
        for (int to : g[i]) if (par[to] == to) {
            ++deg[i];
        }
    }
    int st = -1;
    forn(i, n) if (par[i] == i && deg[i] <= 1) {
        st = i;
    } else if (par[i] == i && deg[i] > 2) {
        cout << "NO" << endl;
        return 0;
    }
    if (st == -1) {
        cout << "NO" << endl;
        return 0;
    }
    ans[st] = 1;
    int cur = 2;
    while (true) {
        bool done = true;
        for (int to : g[st]) if (par[to] == to && ans[to] == 0) {
            ans[to] = cur++;
            st = to;
            done = false;
            break;
        }
        if (done) {
            break;
        }
    }
    forn(i, n) if (ans[par[i]] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    printf("YES\n");
    forn(i, n) {
        printf("%d ", ans[par[i]]);
    }
    return 0;
}