#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int C = 1024;
int n, k, x;
int cnt[C] = {}, ncnt[C];

int main() {
    scanf("%d%d%d", &n, &k, &x);
    forn(i, n) {
        int val;
        scanf("%d", &val);
        ++cnt[val];
    }
    forn(_, k) {
        memset(ncnt, 0, sizeof ncnt);
        int from = 1;
        forn(i, C) {
            int cur = (cnt[i] + from) >> 1;
            ncnt[i ^ x] += cur;
            ncnt[i] += cnt[i] - cur;
            from = (from + cnt[i]) & 1;
        }
        memcpy(cnt, ncnt, sizeof cnt);
    }
    int mn = -1, mx = -1;
    forn(i, C) {
        if (cnt[i]) {
            mx = i;
            if (mn == -1) {
                mn = i;
            }
        }
    }
    cout << mx << ' ' << mn << endl;
    return 0;
}