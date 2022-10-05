#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m = 1e9;
    for (int i = 0; i < n; ++i) m = min(m, a[i]);
    int last = -1;
    int best = 1e9;
    for (int i = 0; i < n; ++i) {
        if (a[i] == m) {
            if (last != -1) {
                best = min(best, i - last);
            }
            last = i;
        }
    }
    cout << best << endl;
}