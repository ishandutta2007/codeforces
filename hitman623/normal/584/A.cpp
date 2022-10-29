#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,t,i;
    cin>>n>>t;
    if(t==10)
    {
        if(n==1) cout<<-1;
        else
        {
            for(i=0;i<n-1;++i)
            cout<<1;
            cout<<0;
        }
        exit(0);
    }
    for(i=0;i<n;++i)
    cout<<t;
    return 0;
}