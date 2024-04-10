#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int SZ = 10000005;

int n, k;
LL cnt[SZ];
LL sum = 0;

int main() {
    scanf("%d%d", &n, &k);
    LL tot = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        tot += x;
    }
    if (tot < k) {
        cout << -1 << endl;
        return 0;
    }
    int bound = 1;
    for (int i = SZ - 1; i > 0; --i) {
        sum += cnt[i];
        if (sum >= k) {
            bound = i;
            break;
        }
    }
    for (int i = SZ - 1; i > 1; --i) {
        if (i / 2 < bound) {
            break;
        }
        cnt[i / 2] += cnt[i];
        cnt[i - i / 2] += cnt[i];
        sum += cnt[i];
        cnt[i] = 0;
        while (sum - cnt[bound] >= k) {
            sum -= cnt[bound];
            ++bound;
        }
    }
    cout << bound << endl;
    return 0;
}