#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,i,x[105],m=0,mn=1e9,f1=1,f2=0,ans;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x[i];
        m=max(x[i],m);
        mn=min(x[i],mn);
    }
    for(i=0;i<n;++i)
    {
        if(x[i]==m && f1) {ans=i;f1=0;}
        if(x[i]==mn) f2=i;
    }
    if(ans<f2)
    cout<<(ans+n-f2-1);
    else cout<<ans+n-f2-2;
    return 0;
}