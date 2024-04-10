#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> divisors = {1};
        int sz = 1;
        int copy_n = n;
        for (int i = 2; i * i <= copy_n; ++i) {
            if (copy_n % i == 0) {
                divisors.push_back(n / i);
                sz += n / i;
                while (copy_n % i == 0) {
                    copy_n /= i;
                }
            }
        }
        if (copy_n > 1 && n != copy_n) {
            divisors.push_back(n / copy_n);
            sz += n / copy_n;
        }
        ll* sums = new ll[sz];
        int hm = 0;
        multiset<ll> s;
        for (int d : divisors) {
            for (int i = 0; i < d; ++i) {
                sums[hm + i] = 0;
                for (int j = i; j < n; j += d) {
                    sums[hm + i] += a[j] * d;
                }
                s.insert(sums[hm + i]);
            }
            hm += d;
        }
        cout << *s.rbegin() << '\n';
        while (q--) {
            int p, x;
            cin >> p >> x;
            --p;
            hm = 0;
            for (int d : divisors) {
                int num = hm + p % d;
                s.erase(s.find(sums[num]));
                sums[num] += (x - a[p]) * 1ll * d;
                s.insert(sums[num]);
                hm += d;
            }
            a[p] = x;
            cout << *s.rbegin() << '\n';
        }
        delete[] sums;
    }
    return 0;
}