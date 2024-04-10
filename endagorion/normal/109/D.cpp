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

bool happy(int x) {
    if (x == 0) {
        return true;
    }
    if (x % 10 != 4 && x % 10 != 7) {
        return false;
    }
    return happy(x / 10);
}

void sswap(int x, int y, vector< int > &m, vector< int > &inv, 
           vector< pair< int, int > > &ans) {
    if (x == y) {
        return;
    }
    ans.push_back(make_pair(x + 1, y + 1));
    swap(m[x], m[y]);
    inv[m[x]] = x;
    inv[m[y]] = y;
}

int main() {
    int n;
    cin >> n;
    vector< int > numbers(n);
    bool scr = false;
    int hap = -1;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        if (i > 0 && numbers[i] < numbers[i - 1]) {
            scr = true;
        }
        if (happy(numbers[i])) {
            hap = i;
        }
    }
    if (!scr) {
        cout << 0 << '\n';
        return 0;
    }
    if (scr && hap == -1) {
        cout << -1 << '\n';
        return 0;
    }

    vector< pair< int, int > > pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = make_pair(numbers[i], i);
    }

    sort(pairs.begin(), pairs.end());
    vector< int > inv(n), m(n);
    for (int i = 0; i < n; ++i) {
        m[pairs[i].second] = i;
        inv[i] = pairs[i].second;
    }
    int phap = m[hap];

    vector< pair< int, int > > ans;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == i) {
            continue;
        }
        sswap(i, inv[phap], m, inv, ans);
        sswap(i, inv[i], m, inv, ans);
    }

    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}