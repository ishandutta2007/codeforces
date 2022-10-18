#include <iostream>

using namespace std;
int n,k,a[50];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int last = a[k-1];
    int res=0;
    if (last == 0) {
        for (int i = 0; a[i] && i < n; ++i)
            ++res;
    }
    else {
        for (int i = 0; a[i] >= last  && i < n; ++i)
            ++res;
    }
    cout << res;
    return 0;
}