#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll xa,ya,xb,yb,xc,yc,s;

int main()
{
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    s = (xa - xb) * (ya + yb) + (xb - xc) * (yb + yc) + (xc - xa) * (yc + ya);
    if (s == 0) cout << "TOWARDS";
    else if (s < 0) cout << "RIGHT";
    else cout << "LEFT";

    return 0;
}