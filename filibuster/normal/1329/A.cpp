#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;


/*
2 1
2

3 3
1 3 1
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    li s = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        s += a[i];
        if(a[i] > n - i) {
            cout << -1;
            exit(0);
        }
    }

    if(a.back() > n - m + 1 || s < n) {
        cout << -1;
        exit(0);
    }

    vector<int> ans(m);

    for(int i = 0; i < m; i++)
        ans[i] = i;

    int b = 0;
    for(int i = m - 1; i >= 0; i--) {
//        cout << b + i + a[i] << endl;
        if(b + i + 1 >= n)
            break;

        int d = min(n - b - i, a[i]);
        b += d;
//        cout << i << ' ' << d << endl;
        ans[i] = n - b;
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}