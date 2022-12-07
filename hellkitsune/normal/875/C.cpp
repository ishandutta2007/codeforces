#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> a[100005];
int cap[100005];
vector<int> all;
vector<int> g[100005];

void dfs(int v) {
    cap[v] = 1;
    for (int to : g[v]) if (!cap[to]) {
        dfs(to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int len;
        scanf("%d", &len);
        a[i].resize(len);
        forn(j, len) {
            scanf("%d", &a[i][j]), --a[i][j];
        }
    }
    forn(i, n - 1) {
        int pos = 0;
        int sz0 = (int)a[i].size();
        int sz1 = (int)a[i + 1].size();
        while (pos < min(sz0, sz1) && a[i][pos] == a[i + 1][pos]) {
            ++pos;
        }
        if (pos == min(sz0, sz1)) {
            if (sz0 > sz1) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (a[i][pos] > a[i + 1][pos]) {
                cap[a[i][pos]] = 1;
            } else {
                g[a[i + 1][pos]].pb(a[i][pos]);
            }
        }
    }
    forn(i, m) if (cap[i]) {
        dfs(i);
    }
    forn(i, n - 1) {
        int pos = 0;
        int sz0 = (int)a[i].size();
        int sz1 = (int)a[i + 1].size();
        while (pos < min(sz0, sz1) && a[i][pos] == a[i + 1][pos]) {
            ++pos;
        }
        if (pos == min(sz0, sz1)) {
            continue;
        }
        int le = a[i][pos] - cap[a[i][pos]] * m;
        int ri = a[i + 1][pos] - cap[a[i + 1][pos]] * m;
        if (le > ri) {
            cout << "No" << endl;
            return 0;
        }
    }
    forn(i, m) if (cap[i]) {
        all.pb(i + 1);
    }
    printf("Yes\n%d\n", (int)all.size());
    for (int x : all) printf("%d ", x);
    puts("");
    return 0;
}