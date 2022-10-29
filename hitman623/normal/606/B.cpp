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
    long x,y,a,b,visi[505][505]={0},c=0,i,j;
    cin>>x>>y>>a>>b>>s;
    cout<<1<<" ";
    visi[a][b]=1;
    for(i=0;i<s.length()-1;++i)
    {
        if(b==1 && s[i]=='L') cout<<0<<" ";
        else if(b==y && s[i]=='R') cout<<0<<" ";
        else if(a==1 && s[i]=='U') cout<<0<<" ";
        else if(a==x && s[i]=='D') cout<<0<<" ";
        else
        {
            if(s[i]=='L') b--;
            if(s[i]=='R') b++;
            if(s[i]=='U') a--;
            if(s[i]=='D') a++;
            if(!visi[a][b])
            cout<<1<<" ";
            else cout<<0<<" ";
            visi[a][b]=1;
        }
    }
    if(s[i]=='L' && b!=1) b--;
    if(s[i]=='R' && b!=y) b++;
    if(s[i]=='U' && a!=1) a--;
    if(s[i]=='D' && a!=x) a++;
    if(!visi[a][b]) c--;
    visi[a][b]=1;
    for(i=1;i<=x;++i)
    for(j=1;j<=y;++j)
    if(visi[i][j]) c++;
    cout<<x*y-c;
    return 0;
}