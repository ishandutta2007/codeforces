#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    double y1, y2, yw, xb, yb, r, x, x2, sin;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    x=xb/(2*(yw-r)-yb-y1-r)*(yw-y1-2*r);
    sin = (xb-x)/sqrt((yw-r-yb)*(yw-r-yb)+(xb-x)*(xb-x));
    if (r/sin+r+y1>y2) cout << -1;
    else cout << fixed << setprecision(10) << x;
    return 0;
}