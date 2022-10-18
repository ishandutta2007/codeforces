#include <iostream>

using namespace std;

long long n,a[1005],sum,res;

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>a[i], sum+=a[i];
    for (int i = 0; i < n; ++i)
        res += (sum-a[i])%2==0;
    cout << res;
    return 0;
}