#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],b[105],res;
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    res = max(2*a[0],a[n-1]);
    if (res >= b[0]) res = -1;
    cout << res;
    return 0;
}