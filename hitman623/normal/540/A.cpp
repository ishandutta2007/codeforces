#include <bits/stdc++.h>

using namespace std;

int main()
{
    long ans=0,n,i;
    char a[1005],b[1005];
    cin>>n;
    cin>>a>>b;
    for(i=0;i<n;++i)
    {
        ans+=min(abs(b[i]-a[i]),10-abs(b[i]-a[i]));
    }
    cout<<ans;
    return 0;
}