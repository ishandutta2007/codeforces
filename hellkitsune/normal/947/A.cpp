#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int calc(int n) {
    int res = n;
    int rem = n;
    for (int i = 2; i * i <= rem; ++i) {
        if (rem % i == 0) {
            rem /= i;
            if (i != n) {
                res = min(res, n - i + 1);
            }
            while (rem % i == 0) {
                rem /= i;
            }
        }
    }
    if (rem > 1 && rem != n) {
        res = min(res, n - rem + 1);
    }
    return res;
}

int main() {
    cin >> n;
//    n = 999958;
    int x = calc(n);
    int ans = n;
    for (int i = x; i <= n; ++i) {
        ans = min(ans, calc(i));
    }
    cout << ans << endl;
    return 0;
}