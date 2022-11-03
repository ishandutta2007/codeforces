#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    li d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    if(d <= k) {
        cout << d * a << endl;
        return 0;
    }

    li ans = 0;
    ans += k * a;
    d -= k;

    ans += min(min(d * b, (d + k - 1) / k * t + d * a),
               (d / k) * (t + k * a) + b * (d % k));

    cout << ans << endl;
}