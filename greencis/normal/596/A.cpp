#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,x[9],y[9];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    if (n == 1) cout << -1, exit(0);
    if (n == 2) {
        if (x[0] == x[1] || y[0] == y[1]) cout << -1, exit(0);
        cout << abs(x[0] - x[1]) * abs(y[0] - y[1]);
    }
    if (n >= 3) {
        cout << max(abs(x[0] - x[1]), max(abs(x[1] - x[2]), abs(x[2] - x[3 % n]))) *
                max(abs(y[0] - y[1]), max(abs(y[1] - y[2]), abs(y[2] - y[3 % n])));
    }

    return 0;
}