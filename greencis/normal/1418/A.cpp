#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll x, y, k;
        cin >> x >> y >> k;
        // += (x - 1) sticks
        // -= (y) sticks,  += (1) coal
        ll need = (k * y + k - 1 + (x - 2)) / (x - 1) + k;
        if (need < 0) need = 0;
        cout << need << '\n';
    }
}