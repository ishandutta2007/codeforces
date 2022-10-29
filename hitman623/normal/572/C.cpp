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
    long a,b,c,l,ans=0,d,i;
    cin>>a>>b>>c>>l;
    for(i=0;i<=l;++i)
    {
        d=min(a-b-c+i,l-i);
        if(d>=0)
        ans+=((d+1)*(d+2))/2;
        d=min(b-a-c+i,l-i);
        if(d>=0)
        ans+=((d+1)*(d+2))/2;
        d=min(c-b-a+i,l-i);
        if(d>=0)
        ans+=((d+1)*(d+2))/2;
    }
    cout<<((l+3)*(l+2)*(l+1))/6-ans;
    return 0;
}