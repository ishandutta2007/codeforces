#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = 0;
    int cnt = 0;
    int mx = 0;
    for(int i = 1; i < n - 1; i++) {
        ans += (a[i] + 1) / 2;
        cnt += (a[i] % 2);
        mx = max(mx, a[i]);
    }

    if(mx == 1 || n == 3 && cnt == 1)
        cout << "-1\n";
    else
        cout << ans << '\n';
//    if(mx > 1)
//
//    else
//        cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}