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
    long n,s,x,y,i,ans=-1,t;
    cin>>n>>s;
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        if(x>s || (x==s && y!=0)) continue;
        t=(100-y)%100;
        if(t>ans) ans=t;
    }
    cout<<ans;
    return 0;
}