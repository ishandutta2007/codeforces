#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    cout << setprecision(17) << fixed << max((-b + sqrtl(d)) / 2 / a, (-b - sqrtl(d)) / 2 / a) << endl;
    cout << setprecision(17) << fixed << min((-b - sqrtl(d)) / 2 / a, (-b + sqrtl(d)) / 2 / a) << endl;
    return 0;
}