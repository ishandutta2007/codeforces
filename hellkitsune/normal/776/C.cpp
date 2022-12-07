#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[100000];
LL sum[100001];
map<LL, int> cnt;
vector<LL> can;

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);
    if (abs(k) == 1) {
        can.pb(1);
        if (k == -1) {
            can.pb(-1);
        }
    } else {
        for (LL x = 1; abs(x) <= LL(5e14); x *= k) {
            can.pb(x);
        }
    }
    sum[0] = 0;
    forn(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    LL ans = 0;
    forn(i, n + 1) {
        for (LL x : can) {
            LL need = sum[i] - x;
            auto it = cnt.find(need);
            if (it != cnt.end()) {
                ans += it->second;
            }
        }
        ++cnt[sum[i]];
    }
    cout << ans << endl;
    return 0;
}