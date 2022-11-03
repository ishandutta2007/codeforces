#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 14;

void solve() {
    int k;
    cin >> k;

    cout << 100 / __gcd(100, k) << endl;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}