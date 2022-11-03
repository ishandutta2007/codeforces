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
const int N = 2000 + 13;


/*
1
3
1 1 1
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mx, my;
    map<pii, int> mp;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        mx[x]++;
        my[y]++;
        mp[{x, y}]++;
    }

    li ans = 0;
    for(auto p : mx) {
        ans += p.s * 1ll * (p.s - 1) / 2;
    }

    for(auto p : my) {
        ans += p.s * 1ll * (p.s - 1) / 2;
    }

    for(auto p : mp) {
        ans -= p.s * 1ll * (p.s - 1) / 2;
    }

    cout << ans;
}