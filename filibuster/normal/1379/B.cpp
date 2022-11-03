#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int l, r;
    li m;
    cin >> l >> r >> m;

    int k = r - l;

    for(int a = l; a <= r; a++) {
        int p = m % a;
        if(p <= k && m / a > 0) {
            cout << a << ' ' << l + p << ' ' << l << endl;
            return;
        } else if(a - p <= k && m / a + 1 > 0) {
            cout << a << ' ' << l << ' ' << l + a - p << endl;
            return;
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}