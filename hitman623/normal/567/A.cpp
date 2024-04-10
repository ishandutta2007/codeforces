#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    long n,a[100005],i;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        if(i==1) cout<<a[2]-a[1]<<" "<<a[n]-a[1]<<endl;
        else if(i==n) cout<<a[n]-a[n-1]<<" "<<a[n]-a[1]<<endl;
        else cout<<min(a[i+1]-a[i],a[i]-a[i-1])<<" "<<max(a[n]-a[i],a[i]-a[1])<<endl;
    }
    return 0;
}