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
    int n, k;
    cin >> n >> k;

//    cout << min(n, abs(2 * k - n)) << endl;
    cout << max((n + k) % 2, k - n) << endl;;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}