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
    long n,i,a[101],c=0,ans=0;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    i=0;
    while(a[i]==0)
    i++;
    for(;i<n;++i)
    if(a[i]==1)
    {
        if(c<=1) ans+=c+1;
        else ans+=1;
        c=0;
    }
    else c++;
    cout<<ans;
    return 0;
}