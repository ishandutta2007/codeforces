#include <bits/stdc++.h>
using namespace std;

int n;
double p;

int main() {
    cin >> n >> p;
    if (p - 1e-7 < 0) cout << "0\n", exit(0);
    auto calc = [&](int x) {
        return x * (x - 1) * (x - 2) / 6;
    };
    for (int i = 1; i < n; i++) {
        double prob = 0;
        prob += 1.0 * calc(i) / calc(n);
        prob += 1.0 * i * (n - i) * (n - i - 1) / 2 / calc(n) / 2;
        prob += 1.0 * i * (i - 1) / 2 * (n - i) / calc(n);
        if (prob > p - 1e-7) {
            cout << i << '\n', exit(0);
        }
    }
    cout << n << '\n';
    return 0;
}
// 217 0.0744