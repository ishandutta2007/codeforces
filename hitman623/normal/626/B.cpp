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
    string s;
    long n,i,r=0,g=0,b=0;
    cin>>n>>s;
    for(i=0;i<n;++i)
    if(s[i]=='G') g++;
    else if(s[i]=='B') b++;
    else if(s[i]=='R') r++;
    if(r && b && g)
    {
        cout<<"BGR";
    }
    else if(!!r+!!b==2)
    {
        if(r>=2 && b>=2) cout<<"BGR";
        else if(r>=2) cout<<"BG";
        else if(b>=2) cout<<"GR";
        else cout<<"G";
    }
    else if(!!r+!!g==2)
    {
        if(r>=2 && g>=2) cout<<"BGR";
        else if(r>=2) cout<<"BG";
        else if(g>=2) cout<<"BR";
        else cout<<"B";
    }
    else if(!!g+!!b==2)
    {
        if(g>=2 && b>=2) cout<<"BGR";
        else if(g>=2) cout<<"BR";
        else if(b>=2) cout<<"GR";
        else cout<<"R";
    }
    else if(r) cout<<"R";
    else if(b) cout<<"B";
    else cout<<"G";
    return 0;
}