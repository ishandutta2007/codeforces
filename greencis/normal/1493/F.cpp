#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

bool query(int h, int w, int i1, int j1, int i2, int j2) {
    cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> primes;
    for (int i = 3; i <= 1000; ++i) {
        bool good = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                good = false;
                break;
            }
        }
        if (good) primes.push_back(i);
    }

    int n, m;
    cin >> n >> m;
    int ans = 1;

    int cur = 1;
    while (m % 2 == 0) {
        if (!query(n, m / 2, 1, 1, 1, 1 + m / 2))
            break;
        m /= 2;
        ++cur;
    }
    ans *= cur;

    for (int x : primes) {
        cur = 1;
        while (m % x == 0) {
            if (!query(n, m / x * (x - 1) / 2, 1, 1, 1, 1 + m / x * (x - 1) / 2))
                break;
            if (!query(n, m / x * (x - 1) / 2, 1, 1, 1, 1 + m / x * (x + 1) / 2))
                break;
            m /= x;
            ++cur;
        }
        ans *= cur;
    }

    cur = 1;
    while (n % 2 == 0) {
        if (!query(n / 2, m, 1, 1, 1 + n / 2, 1))
            break;
        n /= 2;
        ++cur;
    }
    ans *= cur;

    for (int x : primes) {
        cur = 1;
        while (n % x == 0) {
            if (!query(n / x * (x - 1) / 2, m, 1, 1, 1 + n / x * (x - 1) / 2, 1))
                break;
            if (!query(n / x * (x - 1) / 2, m, 1, 1, 1 + n / x * (x + 1) / 2, 1))
                break;
            n /= x;
            ++cur;
        }
        ans *= cur;
    }

    cout << "! " << ans << endl;
}