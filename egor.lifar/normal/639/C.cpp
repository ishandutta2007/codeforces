#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>

using namespace std;

int a[500000];

int main() {
    //freopen("input.txt", "r");
    //freopen("output.txt", "w");

    int n, k;
    scanf("%d %d", &n, &k);
    n += 1;

    vector<int> v(n);
    for (auto &x : v) {
        scanf("%d", &x);
    }

    for (int i = 0; i < n; i++) {
        a[i] = v[i];
    }

    for (int i = 0; i < n + 100; i++) {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;

        if (a[i] == -1) {
            a[i] = 1;
            a[i + 1] -= 1;
        }
    }

    bool invert = false;

    if (a[n + 100] < 0) {
        invert = true;

        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            a[i] = -v[i];
        }

        for (int i = 0; i < n + 100; i++) {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;

            if (a[i] == -1) {
                a[i] = 1;
                a[i + 1] -= 1;
            }
        }
    }

    int last = -1;
    int first = -1;
    for (int i = 0; i < n + 100; i++) {
        if (a[i] == 1) {
            last = i;
            if (first == -1) {
                first = i;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (i + 35 < last || first < i) {
            continue;
        }

        long long cur = 0;
        for (int j = i + 40; j >= i; j--) {
            cur = cur * 2 + a[j];
        }

        long long zero = invert ? v[i] : -v[i];

        long long mx = k - zero;

        if (i == n - 1 && cur == -zero) {
            continue;
        }

        if (cur <= mx) {
//            printf("%d: %d %d %d\n", i, cur, zero, (cur + zero) * (invert ? 1 : -1));
            ans += 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}