#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
int used[100000] = {};
int col = 0;
int cnt[201][100000] = {};
int tot[201] = {};
int r[201] = {};

const int MAX = 500;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];
    for (int k = 1; k <= MAX; ++k) {
        if (k > n) {
            puts("");
            return 0;
        }
        int pos = 0;
        int res = 0;
        while (pos < n) {
            ++col;
            ++res;
            int cnt = 0;
            while (pos < n && cnt <= k) {
                if (used[a[pos]] != col) {
                    used[a[pos]] = col;
                    ++cnt;
                }
                ++pos;
            }
            if (cnt > k) {
                --pos;
            }
        }
        printf("%d ", res);
    }
    if (n == MAX) {
        puts("");
        return 0;
    }
    int k = MAX + 1;
    int pos = 0;
    int res = 0;
    while (pos < n) {
        while (pos < n && tot[res] <= k) {
            if (cnt[res][a[pos]] == 0) {
                ++tot[res];
            }
            ++cnt[res][a[pos]];
            ++pos;
        }
        if (tot[res] > k) {
            --pos;
            --cnt[res][a[pos]];
            --tot[res];
        }
        r[res] = pos;
        ++res;
    }
    printf("%d ", res);
    while (res > 1) {
        ++k;
        int pos = 0;
        res = 0;
        while (pos < n) {
            pos = r[res];
            while (pos < n && tot[res] <= k) {
                if (cnt[res][a[pos]] == 0) {
                    ++tot[res];
                }
                ++cnt[res][a[pos]];
                if (--cnt[res + 1][a[pos]] == 0) {
                    --tot[res + 1];
                }
                ++pos;
            }
            if (tot[res] > k) {
                --pos;
                --cnt[res][a[pos]];
                --tot[res];
                if (++cnt[res + 1][a[pos]] == 1) {
                    ++tot[res + 1];
                }
            }
            r[res] = pos;
            ++res;
        }
        printf("%d ", res);
    }
    for (++k; k <= n; ++k) {
        printf("1 ");
    }
    puts("");
    return 0;
}