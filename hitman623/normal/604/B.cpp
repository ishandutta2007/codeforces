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
long n,k,i,s[100005],t,ans;
int main()
{
    io
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>s[i];
    ans=s[n-1];
    t=min(n-1,2*(n-k)-1);
    for(i=0;i<=t;++i)
    ans=max(ans,s[i]+s[t-i]);
    cout<<ans;
    return 0;
}