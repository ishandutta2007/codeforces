#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int n;
int a[N];
int t[4 * N];

void build(int v, int l, int r) {
//    cout << v << ' ' <<l << ' ' << r << endl;
    if(r - l == 1) {
        t[v] = l;
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    if(a[t[v * 2 + 1]] > a[t[v * 2 + 2]])
        t[v] = t[v * 2 + 1];
    else
        t[v] = t[v * 2 + 2];
}

int get(int v, int l, int r, int ql, int qr) {
    if(l >= qr || r <= ql)
        return n;

    if(ql <= l && r <= qr)
        return t[v];

    int m = (l + r) / 2;
    int i1 = get(v * 2 + 1, l, m, ql, qr);
    int i2 = get(v * 2 + 2, m, r, ql, qr);

    if(a[i1] > a[i2])
        return i1;
    else
        return i2;
}

li dp[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
        cin >> a[i];

    a[n - 1] = n;

    build(0, 0, n);
//cout << "g" << endl;
    li ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        int mx = get(0, 0, n, i, a[i]);
        dp[i] = dp[mx] + mx - i + n - a[i];
        ans += dp[i];
//        cout << i << ' ' << dp[i] << ' ' << mx << endl;
    }

    cout << ans << endl;
}