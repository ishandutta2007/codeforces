#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    cout << 3 * n + 4 << endl;

    cout << -1 << ' ' << 0 << endl;
    cout << -1 << ' ' << 1 << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++)
            cout << i << ' ' << i + j << endl;
    }

    cout << n << ' ' << n << endl;
    cout << n << ' ' << n + 1 << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}