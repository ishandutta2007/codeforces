#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

void solve() {
    int n, r;
    cin >> n >> r;

    int m = min(n - 1, r);

    cout << m * 1ll * (m + 1) / 2 + (n <= r) << endl;

//    vector<>
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}