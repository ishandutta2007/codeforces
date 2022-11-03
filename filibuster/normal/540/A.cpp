#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 1e9 + 13;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int res = abs(a[i] - b[i]);
        ans += min(res, 10 - res);
    }

    cout << ans;
}