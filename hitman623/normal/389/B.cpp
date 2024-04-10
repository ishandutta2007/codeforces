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
    string s[101];
    long v[101][101]={0},n,i,j,c=0,h=0;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=1;i<n-1;++i)
    for(j=1;j<n-1;++j)
    if(!v[i][j] && s[i][j]=='#' && s[i][j-1]=='#' && s[i][j+1]=='#' && s[i-1][j]=='#' && s[i+1][j]=='#')
    {
        c++;
        v[i+1][j]=1;
        v[i][j+1]=1;
        v[i+2][j]=1;
        v[i][j+2]=1;
        v[i+1][j+1]=1;
    }
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    h+=(s[i][j]=='#');
    if(5*c!=h) cout<<"NO";
    else cout<<"YES";
    return 0;
}