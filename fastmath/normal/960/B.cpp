#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
 
using namespace std;
#define int long long

const int MAXN = 1007;

int a[MAXN], b[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    
    int c = x + y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector <int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(abs(a[i] - b[i]));
    }

    int sum = 0;
    for (int elem : v) {
        sum += elem;
    }

    if (sum <= c) {
        if ((c - sum) % 2) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
        return 0;
    }

    for (int it = 0; it < c; ++it) {
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (v[mx] < v[i]) mx = i;
        }
        --v[mx];
    }

    int ans = 0;
    for (int elem : v) {
        ans +=  elem * elem;
    }

    cout << ans << '\n';
    return 0;
}