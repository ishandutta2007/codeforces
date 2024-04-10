#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

string s;

ll solve(int l, int r, char c) {
    if (l == r-1) return s[l] == c ? 0 : 1;
    int m = (l+r)/2;
    ll x = 0, y = 0;
    for (int i = l; i < m; i++) x += s[i] != c;
    for (int i = m; i < r; i++) y += s[i] != c;
    return min(solve(l, m, c+1)+y, solve(m, r, c+1)+x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin >> s;
        cout << solve(0, n, 'a') << "\n";
    }
}