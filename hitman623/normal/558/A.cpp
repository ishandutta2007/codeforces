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
    pll v[102];
    long n,i,x,y,c=0,ans=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>v[i].x>>v[i].y;
        if(v[i].x>0) c++;
    }
    sort(v,v+n);
    if(c<n-c)
    {
        c++;
        for(i=n-1;i>=0;i--)
        {
            if(v[i].x<0) c--;
            if(c>=0)
            ans+=v[i].y;
        }
    }
    else
    {
        c=n-c+1;
        for(i=0;i<n;i++)
        {
            if(v[i].x>0) c--;
            if(c>=0)
            ans+=v[i].y;
        }
    }
    cout<<ans;
    return 0;
}