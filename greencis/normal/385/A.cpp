#include <iostream>

using namespace std;
int n,c,a[105],res=0;

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; ++i)
        res = max(res,a[i]-a[i+1]-c);
    cout << res;

    return 0;
}