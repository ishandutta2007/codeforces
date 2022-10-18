#include <iostream>
#include <algorithm>
using namespace std;

int a[102];

int comp(int a, int b) {
    return a > b;
}

int main()
{
    int n,sum=0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin>>a[i],sum+=a[i];
    sort(a,a+n,comp);
    int r=0,sum2 = 0;
    while (sum >= sum2) {
        sum2 += a[r];
        sum -= a[r];
        r++;
    }
    cout << r;

    return 0;
}