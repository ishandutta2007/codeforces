#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*
5 10
99.99

1
5 4 1
1 5 4 3 2

1
3 5
1 2
3 4

1
2 1000000000
1 1
999999999 999999999
*/

void solve() {
    int n, k;
    pii a, b;
    cin >> n >> k >> a.f >> a.s >> b.f >> b.s;

    li cur = 0;
    li d = 0;
    {
        int x1 = max(a.f, b.f);
        int y1 = min(a.s, b.s);
        if(x1 <= y1) {
            cur += (y1 - x1) * 1ll * n;
            d = max(a.s, b.s) - min(a.f, b.f) - (y1 - x1);
        } else {
            d = -max(a.f, b.f) + min(a.s, b.s);
        }

    }

    if(cur >= k) {
        cout << 0 << endl;
        return;
    }

    k -= cur;

    li ans = 0;

//    cout << d << endl;

    if(d >= 0) {
        if(d * 1ll * n >= k) {
            cout << k << endl;
            return;
        } else {
            ans += d * n;
            k -= d * n;
        }

        cout << ans + k * 2 << endl;
        return;
    }

//    cout << d << endl;

    li res = 1e18;
    for(int i = 0; i < n; i++) {
        ans += -d;
        li l = max(a.s, b.s) - min(a.f, b.f);
        if(l >= k) {
            ans += k;
            res = min(res, ans);
            break;
//            cout << ans << endl;
//            return;
        } else {
            ans += l;
            k -= l;
        }

        res = min(res, k * 2 + ans);

    }

    cout << res << endl;
}

//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}