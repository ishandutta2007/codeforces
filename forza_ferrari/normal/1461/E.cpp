#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,l,r,t,x,y;
map<int,bool> mp;
signed main()
{
    cin>>n>>l>>r>>t>>x>>y;
    if(y<x)
    {
        if(n+y>r)
        {
            --t;
            n-=x;
        }
        if(n<l)
        {
            cout<<"NO\n";
            return 0;
        }
        if((n-l)/(x-y)>=t)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        return 0;
    }
    while(t>0)
    {
        if(mp.count(n%x))
        {
            cout<<"YES\n";
            return 0;
        }
        t-=(n-l)/x;
        n-=(n-l)/x*x;
        if(t<=0)
        {
            cout<<"YES\n";
            return 0;
        }
        mp[n%x]=1;
        n+=y;
        if(n<l||n>r)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}