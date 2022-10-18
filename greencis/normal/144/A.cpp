#include <iostream>

using namespace std;

int a[105],n,mx=1,mn=1;

int main()
{
    cin >> n;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
        if(a[mx]<a[i])
            mx=i;
        if(a[mn]>=a[i])
            mn=i;
    }
    if (mx>mn)
        cout << mx-2+n-mn;
    else cout << mx-1+n-mn;
    return 0;
}