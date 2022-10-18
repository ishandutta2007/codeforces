#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main()
{
    ld l1, l2, l3, r1, r2, r3, h1, h2, h3, s1, s2, s3;
    cin >> l1 >> l2 >> l3;
    r1 = l1 / 2 / sinl(acosl(-1) / 3);
    r2 = l2 / 2 / sinl(acosl(-1) / 4);
    r3 = l3 / 2 / sinl(acosl(-1) / 5);
    h1 = sqrtl(l1 * l1 - r1 * r1);
    h2 = sqrtl(l2 * l2 - r2 * r2);
    h3 = sqrtl(l3 * l3 - r3 * r3);
    s1 = 3 * l1 * l1 / tanl(acosl(-1) / 3) / 4;
    s2 = 4 * l2 * l2 / tanl(acosl(-1) / 4) / 4;
    s3 = 5 * l3 * l3 / tanl(acosl(-1) / 5) / 4;
    cout << setprecision(17) << fixed << s1 * h1 / 3 + s2 * h2 / 3 + s3 * h3 / 3;

    return 0;
}