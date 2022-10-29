#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,a[200005],k,i,ans=0;
map < ll , ll > m,mm;
int main()
{
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        ans+=mm[a[i]*k];
        mm[a[i]]+=m[a[i]*k];
        m[a[i]]++;
    }
    cout<<ans;
    return 0;
}