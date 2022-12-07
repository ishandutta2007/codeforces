#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[1001] = {};
bitset<2500> b, nb;
vector<int> pos, neg;

int main() {
    scanf("%d%d", &n, &k);
    forn(i, k) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    if (a[n]) {
        cout << 1 << endl;
        return 0;
    }
    forn(i, 1001) if (a[i]) {
        if (i < n) neg.pb(n - i);
        else pos.pb(i - n);
        b.set(i - n + 1250);
    }
    if (pos.empty() || neg.empty()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 1;
    while (!b.test(1250)) {
        nb.reset();
        for (int x : pos) {
            nb |= b << x;
        }
        for (int x : neg) {
            nb |= b >> x;
        }
        b = nb;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}