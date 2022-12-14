#include <bits/stdc++.h>

using namespace std;

vector<int> egcd(int a, int b) {
    int s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    while (b) {
        int d = a / b;
        tie(a, b) = make_pair(b, a % b);
        tie(s0, s1) = make_pair(s1, s0 - d * s1);
        tie(t0, t1) = make_pair(t1, t0 - d * t1);
    }
    return {a, s0, t0};
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> e = egcd(a, b);
    int g = e[0], x = e[1], y = e[2];
    if (c % g) return cout << "No", 0;

    a /= g, b /= g, c /= g;
    x *= c, y *= c;

    auto shift = [&](int s) {
        x += b * s;
        y -= a * s;
    };

    shift(-x / b);
    if (x < 0) shift(a > 0 ? 1 : -1);

    cout << (y < 0 ? "No" : "Yes");
}