#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    long n,a[100005],i,ans=0,cnt=0;
    char c[100005];
    map < long ,long > mp;
    cin>>n;
    for(i=1;i<=n;++i)
    {cin>>c[i]>>a[i];
    if(mp[a[i]]==0 && c[i]=='-') ans++;
    mp[a[i]]=1;}
    cnt=ans;
    mp.clear();
    for(i=1;i<=n;++i)
    {
        if(c[i]=='+') cnt++;
        else cnt--;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}