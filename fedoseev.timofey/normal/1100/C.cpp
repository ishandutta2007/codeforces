#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, r;
    cin >> n >> r;
    ld mem = (ld)pi * (n - 2) / (2 * n);
    ld kek = cos(mem);
    ld R = r * kek / (1 - kek);
    cout << R << '\n';
}