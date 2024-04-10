#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,a[100];
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    if (k > n) cout << -1;
    else cout << a[n-k] << " "<<a[n-k];
    return 0;
}