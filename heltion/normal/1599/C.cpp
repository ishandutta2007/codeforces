#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    LL N;
    double p;
    cin >> N >> p;
    LL P = p * 10000 + .5;
    for (int i = 0; i <= N; i += 1)
        if (
            (i * (N - i) * (N - i - 1) / 2 + i * (i - 1) / 2 * (N - i) * 2 + i * (i - 1) * (i - 2) / 6 * 2) * 10000
                >= N * (N - 1) * (N - 2) / 6 * P * 2 ) {
            cout << i;
            break;
        }
    return 0;
}