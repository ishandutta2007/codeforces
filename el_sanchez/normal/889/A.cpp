#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

#define FILE_NAME "a"

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MAXN = 200500;

int n;
int rest[MAXN];
vi up[MAXN];

bool read() {
    if (scanf("%d", &n) < 1) {
        return 0;
    }
    
    forn(i, n + 1) {
        rest[i] = 0;
        up[i].clear();
    }
    
    forn(i, n) {
        int x;
        scanf("%d", &x);

        // x -> i + 1
        up[i + 1].pb(x);
    }
    
    return 1;
}
    
void solve() {
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        for (auto v: up[i]) {
            rest[v]++;

            if (rest[i] > 0) {
                rest[i]--;
            } else {
                ans++;   
            }
        }
    }
    cout << ans << '\n';
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    //freopen(FILE_NAME ".out", "w", stdout);
#endif    
    
    while (read()) {
        solve();
    }
    
    return 0;
}