#include<bits/stdc++.h>
using namespace std;

int main() {
long double a, b, c; cin >> a >> b >> c;
b /= a;
c /= a;
b /= 2;
c = sqrt(b * b - c);
cout << fixed << setprecision(10) << -b + c << '\n';
cout << fixed << setprecision(10) << -b - c << '\n';
}