#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, a, b;
unsigned long long C[25000][35];

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    --n;
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        cout << n * (a + b) << endl;
        return 0;
    }
    LL lo = 0, hi = 3e9, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        LL cnt = 0;
        forn(i, 30) {
            LL rem = mid - b * i;
            if (rem >= 0) {
                LL c = rem / a + 1;
                LL tmp = 1;
                for (int x = 0; x <= i; ++x) {
                    tmp = (tmp * (c + x)) / (x + 1);
                    if (tmp > n) break;
                }
                cnt += min(tmp, n);
            }
        }
        if (cnt >= n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    //cerr << lo << endl;

    forn(i, 35) C[0][i] = 0;
    C[0][0] = 1;
    for (int i = 1; i < 25000; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < 35; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    LL ans = 0;
    LL cnt = 0;
    LL mx = 0;
    forn(i, 30) {
        LL rem = lo - b * i;
        if (rem >= 0) {
            LL c = rem / a + 1;
            if (i == 0) {
                cnt += c;
                mx = max(mx, a * (c - 1));
                ans += c * (c - 1) / 2 * a;
            } else {
                mx = max(mx, i * b + a * (c - 1));
                for (int j = 0; j < c; ++j) {
                    cnt += C[i + j][i];
                    ans += C[i + j][i] * (i * b + j * a);
                }
            }
        }
    }
    assert(cnt >= n);
    ans -= mx * (cnt - n);
    ans += n * (a + b);
    cout << ans << endl;
    return 0;
}