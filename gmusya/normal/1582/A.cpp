#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll max_sum = (a + 2 * b + 3 * c) / 2;
        ll cur_sum = 0;
        {
            ll k = min(c, (max_sum - cur_sum) / 3);
            cur_sum += 3 * k;
        }
        {
            ll k = min(b, (max_sum - cur_sum) / 2);
            cur_sum += 2 * k;
        }
        {
            ll k = min(a, (max_sum - cur_sum));
            cur_sum += k;
        }
        cout << a + 2 * b + 3 * c - 2 * cur_sum << '\n';
    }
    return 0;
}