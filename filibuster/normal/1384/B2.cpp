#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int N = 3e5 + 13;

/*

abs(k - i)
k, k - 1, k - 2, k - 3,..., 1, 0, 1, 2, 3,..., k - 1
*/

int a[N];
//int l[N], r[N];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 2 * k - 1;

    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << l << ' ' << r << endl;
        if(a[i] > d) {
            cout << "No" << endl;
            return;
        }

        if(a[i] + k <= d) {
            l = 0;
            r = 2 * k - 1;
            continue;
        }

        int nl = max(0, k + a[i] - d);
        int nr = min(2 * k - 1, d + k - a[i]);
        if(l > 0) {
            nl = max(nl, l + 1);
            nr = min(nr, r + 1);
        }

        if(nr < nl) {
            cout << "No" << endl;
            return;
        }

        l = nl;
        r = nr;
//        cout << i << ' ' << l << ' ' << r << endl;
    }

    cout << "Yes" << endl;
}

/*
1
2 1 1
1 0


1
4 3 4
0 2 4 3
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

}