#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    if(a > b)
        swap(a, b);

    int ans = 0;

    while(a <= n && b <= n) {
        a += b;
        swap(a, b);
        ans++;
    }

    cout << ans << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}