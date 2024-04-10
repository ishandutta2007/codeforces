#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(10);
    int R,x1,y1,x2,y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    complex<double> c(x1, y1);
    complex<double> p(x2, y2);
    if (c == p) {
        cout << c.real() + R/2.0 << " " << c.imag() << " " << R/2.0 << '\n';
    } else if (abs(c-p) < R) {
        complex<double> ans = p + (abs(c-p) + R)/(2 * abs(c-p)) * (c-p);
        cout << ans.real() << " " << ans.imag() << " " << (abs(c-p) + R) / 2 << '\n';
    } else {
        cout << c.real() << " " << c.imag() << " " << R << '\n';
    }
}