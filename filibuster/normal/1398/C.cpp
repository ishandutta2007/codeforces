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
const int K = 10;

/*
2 1 9
1 2 1
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        a[i] = c - '0';
    }

    map<int, int> mp;
    mp[0] = 1;

    li ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i];

        int d = i + 1 - cur;
        ans += mp[d];
        mp[d]++;
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}