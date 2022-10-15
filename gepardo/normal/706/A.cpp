#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long double a, b; cin >> a >> b;
    int n; cin >> n;
    long double ans = 1e30;
    for (int i = 0; i < n; i++)
    {
        long double x, y, v; cin >> x >> y >> v;
        ans = min(ans, sqrt((a-x)*(a-x) + (b-y)*(b-y)) / v);
    }
    cout << setprecision(10) << ans << endl;
}