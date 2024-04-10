#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, dp[1005][2005][4];
const int mod = 998244353;
const int a[4][4] = {
{ 0, 1, 1, 1 },
{ 0, 0, 2, 0 },
{ 0, 2, 0, 0 },
{ 1, 1, 1, 0 }
};

inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll l, r;
    cin >> l >> r;
    cout << "YES\n";
    for (; l <= r; l += 2)
        cout << l << " " << l + 1 << "\n";
}