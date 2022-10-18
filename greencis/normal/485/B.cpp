#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,x,y,mxx=-9e18,mnx=9e18,mxy=-9e18,mny=9e18;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x >> y;
        mxx = max(mxx, x);
        mnx = min(mnx, x);
        mxy = max(mxy, y);
        mny = min(mny, y);
    }
    x = max(mxx-mnx,mxy-mny);
    cout << x * x;
    return 0;
}