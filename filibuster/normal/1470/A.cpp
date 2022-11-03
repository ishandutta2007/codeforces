#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 12;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    int cur = 0;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        if(cur >= a[i]) {
            ans += b[a[i]];
        } else {
            ans += b[cur];
            cur++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}