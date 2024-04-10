#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
    ld d,l,v1,v2;
    cin >> d >> l >> v1 >> v2;
    cout << setprecision(17) << fixed << max(ld(0), l - d) / (v1 + v2);

    return 0;
}