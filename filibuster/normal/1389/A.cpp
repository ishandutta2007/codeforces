#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e6 + 13;

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

/*
5 10
99.99
*/

void solve() {
    int l, r;
    cin >> l >> r;

    if(l * 2 > r)
        cout << -1 << ' ' << -1 << endl;
    else
        cout << l << ' '<< l * 2 << endl;
}

//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}