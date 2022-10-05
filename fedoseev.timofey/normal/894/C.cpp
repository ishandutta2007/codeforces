#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <random>

using namespace std;
vector <int> used(1e6 + 7);
/*long long pow(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2) {
        long long tmp = pow(a, n / 2);
        return (tmp * tmp) % md;
    }
    else {
        return (pow(a, n - 1) * a) % md;
    }
} */

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    bool z;
    cin >> n;
    vector <int> a;
    z = true;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
        if (i > 0) {
            if (x % a[0] != 0) z = false;
        }
    }
    if (z) {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << a[i] << " " << a[0] << " ";
        }
        cout << a[n - 1] << " ";
    }
    else cout << -1 << endl;
}