#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int n,l[99],r[99],u[99];
ld ans;

int main()
{
    cin >> n;
    int mxl = -2e9;
    int mxr = -2e9;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        mxl = max(mxl, l[i]);
        mxr = max(mxr, r[i]);
    }

    int mask = (1 << n);
    while (mask--) {
        for (int i = 0; i < n; ++i) u[i] = 0;
        int qqq = mask;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (qqq & 1) u[i] = 1, ++cnt;
            qqq >>= 1;
        }
        if (cnt == 0) continue;
        if (cnt == 1) {

        } else {
            for (int k = 1; k <= 10000; ++k) {
                ld cur = 1ll;
                for (int i = 0; i < n; ++i) {
                    if (u[i]) cur *= ld(l[i] <= k && k <= r[i]);
                    else {
                        if (k < l[i]) cur = 0ll;
                        else if (k > r[i]) cur *= ld(r[i] - l[i] + 1);
                        else cur *= ld(k - l[i]);
                    }
                }
                ans += ld(k) * cur;
            }
        }
    }

    for (int z = 0; z < n; ++z) {
        mask = (1 << n);
        while (mask--) {
            for (int i = 0; i < n; ++i) u[i] = 0;
            int qqq = mask;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (qqq & 1) u[i] = 1, ++cnt;
                qqq >>= 1;
            }
            if (u[z]) continue;
            if (cnt == 0) continue;

            for (int k = 1; k <= 10000; ++k) {
                ld cur = r[z] - max(l[z]-1, k);
                if (r[z] <= max(l[z]-1, k)) continue;
                for (int i = 0; i < n; ++i) {
                    if (i == z) continue;
                    if (u[i]) cur *= ld(l[i] <= k && k <= r[i]);
                    else {
                        if (k < l[i]) cur = 0ll;
                        else if (k > r[i]) cur *= ld(r[i] - l[i] + 1);
                        else cur *= ld(k - l[i]);
                    }
                }
                ans += ld(k) * cur;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        ans /= ld(r[i] - l[i] + 1);
    cout.precision(17);
    cout << fixed << ans;

    return 0;
}