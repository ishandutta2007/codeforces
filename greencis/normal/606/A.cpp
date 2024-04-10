#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int a,b,c,x,y,z;

int main()
{
    cin >> a >> b >> c >> x >> y >> z;
    int extra = max(a - x, 0) / 2 + max(b - y, 0) / 2 + max(c - z, 0) / 2;
    if (a > x) a = x;
    if (b > y) b = y;
    if (c > z) c = z;
    if (a + b + c + extra >= x + y + z) cout << "Yes";
    else cout << "No";

    return 0;
}