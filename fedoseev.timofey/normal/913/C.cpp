#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

vector <vector <int>> g;

int m_pow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int t = m_pow(a, n / 2);
        return t * t;
    }
    return a * m_pow(a, n - 1);
}

vector <int> p2(31);

int main() {
    int n;
    ll L;
    cin >> n >> L;
    vector <int> c(n);
    for (int i = 0; i <= 30; ++i) p2[i] = m_pow(2, i);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i + 1 < n; ++i) {
        if (2 * c[i] <= c[i + 1]) {
            c[i + 1] = 2 * c[i];
        }
    }
    ll ans = 1e18;
    ll cur_price = 0;
    for (int i = n - 1; i >= 0; --i) {
        ll cnt = L / p2[i];
        L -= cnt * p2[i];
        cur_price += cnt * c[i];
        if (L == 0) {
            ans = min(ans, cur_price);
        }
        else {
            ans = min(ans, cur_price + c[i]);
        }
    }
    cout << ans << endl;
}