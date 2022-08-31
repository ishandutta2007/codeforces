#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    ll c1=0,c0=0;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='n')
        c1++;
        if(s[i]=='z')
        c0++;
    }
    while(c1)
    {
        cout<<1<<" ";
        c1--;
    }
    while(c0)
    {
        cout<<0<<" ";
        c0--;
    }
    return 0;
}