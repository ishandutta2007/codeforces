#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(int i=0;i<(n/2);i++)
    {
        ans+=(a[i]+a[n-1-i])*(a[i]+a[n-1-i]);
    }
    cout<<ans;
    return 0;
}