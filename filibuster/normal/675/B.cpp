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
const int N = 1e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int mx = max(max(a + b, a + c), max(d + b, d + c));
    int mn = min(min(a + b, a + c), min(d + b, d + c));

    int ans = 0;
    for(int x = 1; x <= n; x++) {
        int y = a - d + x;
        if(1 > y || y > n)
            continue;

        y = a + b + x - c - d;
        if(1 > y || y > n)
            continue;

        y = b - c + x;
        if(1 > y || y > n)
            continue;

        ans++;
    }

    cout << ans * 1ll * n << endl;
}