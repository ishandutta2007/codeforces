#include <iostream>
#include <cmath>

using namespace std;
const int N = 1e5+10;
double a[N];
int main()
{
    int n, m;
    a[0] = 0;
    cin >> m >> n;
    for(int i = 1; i <= m; i++) a[i] = pow(i*1.0/m,n*1.0);
    for(int i = m; i >= 1; i--) a[i] -= a[i-1];
    for(int i = 1; i <= m; i++) a[i] *= i;
    double ans = 0;
    for(int i = 1; i <= m; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}