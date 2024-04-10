#include<bits/stdc++.h>
using namespace std;

int main() {
long double l3, l4, l5; cin >> l3 >> l4 >> l5;
long double res = 0;
res += l3 * l3 * l3 / sqrt(2.L) / 6;
res += l4 * l4 * l4 / sqrt(2.L) / 3;
res += l5 * l5 * l5 * 0.30150283239583172039865527516635153003L;
cout << fixed << setprecision(15) << res << '\n';
}