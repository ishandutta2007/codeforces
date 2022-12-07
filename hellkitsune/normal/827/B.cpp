#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        LL can = mid % 2 + 1;
        can += (LL)k * (mid / 2);
        if (can >= n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int mx = lo / 2;
    cout << lo << endl;
    if (lo % 2 == 0) {
        --n;
        int num = 2;
        while (k) {
            int pre = 1;
            forn(i, mx - 1) {
                if (n == k) break;
                --n;
                printf("%d %d\n", pre, num);
                pre = num;
                ++num;
            }
            --n;
            --k;
            printf("%d %d\n", pre, num);
            ++num;
        }
    } else {
        n -= 2;
        int num = 3;
        printf("%d %d\n", 1, 2);
        while (k) {
            int pre = (k & 1) + 1;
            forn(i, mx - 1) {
                if (n == k) break;
                --n;
                printf("%d %d\n", pre, num);
                pre = num;
                ++num;
            }
            --n;
            --k;
            printf("%d %d\n", pre, num);
            ++num;
        }
    }
    assert(n == 0 && k == 0);
    return 0;
}