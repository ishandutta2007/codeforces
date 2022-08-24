#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

bool check(int x) {
    return x >= 1000 && x <= 2011;
}

int change(int x, int i, int d) {
    int j = 0, p = 1;
    int res = 0;
    while (x > 0) {
        if (j == i) {
            res += p * d;
        } else {
            res += (x % 10) * p;
        }
        ++j;
        p *= 10;
        x /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector< int > ans(n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int res = 10000;
        for (int j = 0; j < 5; ++j) {
            for (int d = 0; d < 10; ++d) {
                int y = change(x, j, d);
                if (check(y) && y >= cur) {
                    res = min(res, y);
                }
            }
        }
        ans[i] = res;
        cur = res;
    }
   
    if (cur == 10000) {
        cout << "No solution\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}