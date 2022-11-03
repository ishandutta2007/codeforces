#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

/*
1
228 21 11 3
*/

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a - b * 1ll * c > 0) {
        cout << -1 << endl;
        return;
    }

    li ans = a;

    int x = a / b / d - 5;

//    cout << x << endl;
    for(int i = max(0, x); i < x + 10; i++) {
//    for(int i = 0; ; i++) {
        if(i * 1ll * d >= c)
            break;

        li res = a * 1ll * (i + 1) - b * 1ll * d * i * (i + 1) / 2;
//        cout << i << ' ' << res << endl;
        ans = max(ans, res);
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