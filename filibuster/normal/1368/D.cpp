#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> cnt(25, 0);
    for(auto x : a) {
        for(int i = 0; i < cnt.size(); i++)
            cnt[i] += ((x & (1 << i)) > 0);
    }

    vector<int> b(n, 0);
    for(int i = 0; i < cnt.size(); i++) {
        for(int j = 0; j < cnt[i]; j++)
            b[j] += (1 << i);
    }

    li ans = 0;
    for(auto x : b)
        ans += x * 1ll * x;

    cout << ans;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}