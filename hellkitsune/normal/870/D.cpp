#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[5000], b[5000], inv[5000], s[5000];

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}

int base;
int cnt = 0;
int ans[5000];
void solve(int x) {
    forn(i, n) a[i] = s[i] ^ x;
    forn(i, n) if (a[i] >= n) {
        return;
    }

    forn(i, n) inv[a[i]] = i;
    if ((a[0] ^ inv[0]) != base) {
        return;
    }
    for (int i = 1; i < n; ++i) {
        if ((inv[i] ^ inv[0]) != b[i]) {
            return;
        }
    }
    if (++cnt == 1) {
        forn(i, n) ans[i] = a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    base = ask(0, 0);
    for (int i = 1; i < n; ++i) {
        a[i] = ask(i, 0) ^ base;
        b[i] = ask(0, i) ^ base;
    }
    forn(i, n) s[i] = a[i];
    forn(i, n) {
        solve(i);
    }
    cout << "!" << endl;
    cout << cnt << endl;
    forn(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}