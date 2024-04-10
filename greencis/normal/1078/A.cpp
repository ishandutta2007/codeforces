#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    ll A, B, C;
    cin >> A >> B >> C;
    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    ld ans = llabs(xa - xb) + llabs(ya - yb);
    ld gxa, gxb, gya, gyb;
    if (A != 0) {
        gxa = ld(-C - B * ya) / A;
        gya = ya;
        gxb = ld(-C - B * yb) / A;
        gyb = yb;
        ans = min(ans, fabs(xa - gxa) + hypot(gxa - gxb, gya - gyb) + fabs(gxb - xb));

        if (B != 0) {
            gxa = ld(-C - B * ya) / A;
            gya = ya;
            gxb = xb;
            gyb = ld(-C - A * xb) / B;
            ans = min(ans, fabs(xa - gxa) + hypot(gxa - gxb, gya - gyb) + fabs(gyb - yb));

            gxa = xa;
            gya = ld(-C - A * xa) / B;
            gxb = ld(-C - B * yb) / A;
            gyb = yb;
            ans = min(ans, fabs(ya - gya) + hypot(gxa - gxb, gya - gyb) + fabs(gxb - xb));
        }
    }
    if (B != 0) {
        gxa = xa;
        gya = ld(-C - A * xa) / B;
        gxb = xb;
        gyb = ld(-C - A * xb) / B;
        ans = min(ans, fabs(ya - gya) + hypot(gxa - gxb, gya - gyb) + fabs(gyb - yb));
    }
    cout << setprecision(17) << fixed << ans << endl;
}