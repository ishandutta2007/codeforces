#pragma GCC optimize("O3")

#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

#define all(a) (a).begin(), (a).end()

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, n;
    cin >> s >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(all(a)) - a.begin());
    if (*min_element(all(a)) > s || *max_element(all(a)) < s) {
        cout << -1;
        return 0;
    }
    n = static_cast<int>(a.size());
    bitset<2001> can;
    for (int& x : a) {
        x -= s;
        can[1000 + x] = true;
    }
    for (int i = 1; i <= 2000; ++i) {
        if (can[1000]) {
            cout << i;
            return 0;
        }
        bitset<2001> new_can;
        for (int& x : a) {
            if (x < 0) {
                new_can |= (can >> abs(x));
            } else {
                new_can |= (can << abs(x));
            }
        }
        swap(can, new_can);
    }
    return 0;
}