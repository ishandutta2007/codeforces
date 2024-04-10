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
    long n,m,x,y,i,v[102]={0},j;
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        cin>>x;
        for(j=0;j<x;++j)
        {
            cin>>y;
            v[y]=1;
        }
    }
    for(i=1;i<=m;++i)
    if(!v[i]) {cout<<"NO";exit(0);}
    cout<<"YES";
    return 0;
}