#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;

vector <int> v[10];

int count(int x) {
    if (x < 10) return x;
    int c = 1;
    while (x > 0) {
        int d = x % 10;
        if (d != 0) c *= d;
        x /= 10;
    }
    return count(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 1e6; ++i) {
        int x = count(i);
        if (x < 10) {
            v[x].push_back(i);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        auto it2 = upper_bound(v[k].begin(), v[k].end(), r);
        auto it1 = lower_bound(v[k].begin(), v[k].end(), l);
        cout << it2 - it1 << endl;
    }
}