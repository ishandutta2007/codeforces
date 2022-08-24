#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< int > a(m), b(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < m; ++j) {
            if (x >= a[j] && x <= b[j]) {
                sum += c[j] + x - a[j];
            }
        }
    }
    cout << sum << '\n';
    return 0;
}