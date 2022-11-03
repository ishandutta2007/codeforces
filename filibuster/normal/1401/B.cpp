#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

void solve() {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    int d = min(z1, y2);
    z1 -= d;
    y2 -= d;

    int sum = d * 2;

    x1 += z1;
    z1 = 0;

    d = min(z2, x1);
    z2 -= d;
    x1 -= d;

    sum -= z2 * 2;

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}