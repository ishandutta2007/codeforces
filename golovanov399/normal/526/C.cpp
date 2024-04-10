#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    // ax1 + bx2 <= C
    // ay1 + by2 = max
    // b(a) = (C - a * x1) / x2
    // ay1 + [(C - a * x1) / x2] * y2 >= q
    // (q - ay1) / y2 <= (C - ax1) / x2
    // a >= ...
    int c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    long long ans = 0;
    for (int i = max(0, c / wb - 100000); i <= c / wb; i++){
        ans = max(ans, 1ll * i * hb + 1ll * (c - i * wb) / wr * hr);
    }
    for (int i = max(0, c / wr - 100000); i <= c / wr; i++){
        ans = max(ans, 1ll * i * hr + 1ll * (c - i * wr) / wb * hb);
    }
    cout << ans << "\n";

    return 0;
}