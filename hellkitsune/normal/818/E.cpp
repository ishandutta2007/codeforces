#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
vector<int> di;
int cnt[20];
int a[100000];
int bad;

void add(int val, int sgn) {
    forn(i, di.size()) {
        while (val % di[i] == 0) {
            if (cnt[i] > 0) --bad;
            cnt[i] += sgn;
            if (cnt[i] > 0) ++bad;
            val /= di[i];
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);
    if (k == 1) {
        cout << (LL)n * (n + 1) / 2 << endl;
        return 0;
    }
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            while (k % i == 0) {
                ++cnt[di.size()];
                k /= i;
            }
            di.pb(i);
        }
    }
    if (k > 1) {
        cnt[di.size()] = 1;
        di.pb(k);
    }
    bad = di.size();
    int j = 0;
    LL ans = 0;
    forn(i, n) {
        while (j < n && bad) {
            add(a[j], -1);
            ++j;
        }
        if (bad) break;
        ans += n + 1 - j;
        add(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}