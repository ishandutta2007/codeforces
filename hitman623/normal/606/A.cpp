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
    long a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    a-=x;
    b-=y;
    c-=z;
    if(a>0) a/=2;
    if(b>0) b/=2;
    if(c>0) c/=2;
    if(a+b+c<0)cout<<"No";
    else cout<<"Yes";
    return 0;
}