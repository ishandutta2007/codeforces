#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int ca = -1;
    int cb = -1;
    for (int i = 0; i <= n; ++i) {
        ll x = (ll)a * i;
        if (n >= x && (n - x) % b == 0) {
            ca = i;
            cb = (n - x) / b;
            break;
        }
    }
    if (ca == -1) {
        cout << -1 << endl;
        return 0;
    }
    int last = 1;
    for (int i = 0; i < ca; ++i) {
        cout << last + a - 1 << " ";
        for (int i = 0; i < a - 1; ++i) {
            cout << last << " ";
            ++last;
        }
        ++last;
    }
    for (int i = 0; i < cb; ++i) {
        cout << last + b - 1 << " ";
        for (int i = 0; i < b - 1; ++i) {
            cout << last << " ";
            ++last;
        }
        ++last;
    }
}