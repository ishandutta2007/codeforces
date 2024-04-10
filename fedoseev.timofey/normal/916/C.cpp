#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

const int Prime = 100003;

const int Inf = 1e8 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << Prime << " " << Prime << endl;
    for (int i = 1; i < n; ++i) {
        if (i == n - 1) {
            cout << n - 1 << " " << n << " " << Prime - n + 2 << endl;
            break;
        }
        cout << i << " " << i + 1 << " " << 1 << endl;
    }
    m -= n - 1;
    int i = 1;
    while (m > 0) {
        for (int j = i + 2; j <= n; ++j) {
            cout << i << " " << j << " " << Inf << endl;
            --m;
            if (m == 0) break;
        }
        ++i;
    }
}