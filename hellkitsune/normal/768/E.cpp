#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

typedef pair<int, LL> S;
map<S, int> g;

bool used[61][62];
int solve(int x, LL mask) {
    if (x == 0) {
        return 0;
    }
    auto it = g.find(mp(x, mask));
    if (it != g.end()) {
        return it->second;
    }
    bool (&used)[62] = ::used[x];
    forn(i, x + 2) {
        used[i] = false;
    }
    for (int i = 1; i <= x; ++i) {
        if (!(mask & (1ll << i))) {
            used[solve(x - i, mask | (1ll << i))] = true;
        }
    }
    int res = 0;
    while (used[res]) {
        ++res;
    }
    return g[mp(x, mask)] = res;
}

int cnt[61] = {};

int main() {
    for (int i = 1; i <= 60; ++i) {
        solve(i, 0);
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    for (int i = 1; i <= 60; ++i) {
        if (cnt[i] & 1) {
            ans ^= solve(i, 0);
        }
    }
    if (ans) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}