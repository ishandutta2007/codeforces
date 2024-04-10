#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main()
{
    ll n;
    ld r,PI = acosl(-1);
    cin >> n >> r;
    cout << setprecision(17) << fixed << n * r * r * sinl(PI / n) * sinl(PI / n / 2) / sinl(PI - PI * 3 / n / 2);

    return 0;
}