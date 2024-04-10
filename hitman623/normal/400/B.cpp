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
    string s[1001];
    long n,m,i,j,g;
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    set < long > v;
    for(i=0;i<n;++i)
    {
        g=-1;
        for(j=0;j<m;++j)
        if(s[i][j]=='G') g=j;
        else if(s[i][j]=='S')
        {
            if(g==-1) {cout<<-1;exit(0);}
            else v.insert(j-g);
        }
    }
    cout<<v.size();
    return 0;
}