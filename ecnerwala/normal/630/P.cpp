#include<bits/stdc++.h>
using namespace std;

const long double PI2 = atan2(1.L, 0.L);

int main() {
int n; long double r; cin >> n >> r;
long double res = r * r * n * sin(PI2 / n) * sin(2 * PI2 / n) / sin(3 * PI2 / n);
cout << fixed << setprecision(10) << res << '\n';
}