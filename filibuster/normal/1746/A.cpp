#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

/*

*/


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    bool fl = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        fl |= (a[i] == 1);
    }

    cout << (fl ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}