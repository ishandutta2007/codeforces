#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define int long long
const int LG = 62;

int a[LG];

int getpos(int level, int val) {
    if (a[level] < 0) {
        if (val <= abs(a[level])) {
            return (1ll << level) - abs(a[level]) + val;
        }
        else {
            return val - abs(a[level]);
        }
    }
    else {
        if ((1ll << level) - val + 1 <= a[level]) {
            return val - ((1ll << level) - a[level]);
        }
        else {
            return val + a[level];
        }
    }
}

int getval(int level, int p, int it) {
    if (a[level] < 0) {
        if (p < (1ll << level) - abs(a[level]) + 1) {
            return p + abs(a[level]);
        }
        else {
            return p - ((1ll << level) - abs(a[level]));
        }
    }
    else {
        if (p <= a[level]) {
            return (1ll << level) - a[level] + p;
        }
        else {
            return p - a[level];
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for (int it = 0; it < q; ++it) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int x, k;
            cin >> x >> k;
            
            int level = 0;
            while ((1ll << level) < x) {
                x -= (1ll << level);
                ++level;
            }
            
            a[level] += k;
            a[level] %= (1ll << level);
        }
        else if (t == 2) {
            int x, k;
            cin >> x >> k;
            
            int level = 0;
            while ((1ll << level) < x) {
                x -= (1ll << level);
                ++level;
            }

            for (int i = level; i < LG; ++i) {
                a[i] += k;
                a[i] %= (1ll << i);
                k *= 2;
            }
        }
        else {  
            int x;
            cin >> x;

            int level = 0;
            while ((1LL << level) < x) {
                x -= (1LL << level);
                ++level;
            }

            int num = getpos(level, x);
            num += (1ll << level) - 1;
            while (level >= 0) {
                cout << getval(level, num - (1ll << level) + 1, it) + (1ll << level) - 1 << ' ';
                num /= 2;
                --level;
            }
            cout << '\n';
        }
    }


    return 0;
}