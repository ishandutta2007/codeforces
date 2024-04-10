#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

int a[MAXN], pref[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];

    int curr = 0;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;

        if (curr + k >= pref[n]) {
            curr = 0;
            cout << n << '\n';
        }
        else {
            curr += k;

            int l = 0;
            int r = n;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (pref[m] <= curr) {
                    l = m;
                }
                else {
                    r = m;
                }
            }

            cout << n - l << '\n';
        }
    }

    return 0;
}