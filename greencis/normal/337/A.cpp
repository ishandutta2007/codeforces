#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a[1005],res = 2e9;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort (a,a+m);
    for (int i = 0; i <= m-n; ++i) {
        res = min(res, a[n-1+i]-a[i]);
    }
    cout<<res;

    return 0;
}