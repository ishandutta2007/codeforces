#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    li s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
        if((i + 1) * 1ll * x > s) {
            cout << i << endl;
            return;
        }
    }

    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}