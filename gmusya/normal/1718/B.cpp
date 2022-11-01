#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;
const ll INF = 1e12;

vector<ll> fib;

void init() {
    fib = {1, 1};
    while (fib.back() < INF) {
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<ll> c(k);
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += c[i];
        }
        int cnt = 0;
        {
            ll tmp = sum;
            bool good = false;
            for (auto& now : fib) {
                tmp -= now;
                ++cnt;
                if (tmp == 0) {
                    good = true;
                    break;
                }
            }
            if (!good) {
                cout << "NO\n";
                continue;
            }
        }
        multiset<ll> values;
        for (auto& now : c) {
            values.insert(now);
        }
        bool good = true;
        for (int i = cnt - 1; i >= 1; --i) {
            ll mx = *values.rbegin();
            values.erase(values.find(mx));
            if (mx < fib[i] || mx >= fib[i + 1] + (1 - i % 2)) {
                good = false;
                break;
            }
            if (values.empty()) {
                good = false;
                break;
            }
            mx -= fib[i];
            if (*values.rbegin() < mx) {
                good = false;
                break;
            }
            values.insert(mx);
        }
        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}