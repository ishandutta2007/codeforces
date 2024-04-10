#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int mx=-1e9,mxi=-1,mn=1e9,mni=-1;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        if (mx < a[i])
        {
            mx = a[i];
            mxi = i;
        }
        if (mn >= a[i]) {
            mn = a[i];
            mni = i;
        }
    }
    if (mni == 0 && mxi == n-1) {
        if (n == 2) {
            cout << a[mxi] << " "<<a[mni];
            return 0;
        }
        int t = a[mxi];
        a[mxi] = a[mni];
        a[mni] = t;
    } else {
        swap(a[0],a[mxi]);
        swap(a[n-1],a[mni]);
    }
    sort(a+1,a+n-1);
    for (int i = 0; i < n; ++i)
        cout << a[i]<<" ";
    return 0;
}