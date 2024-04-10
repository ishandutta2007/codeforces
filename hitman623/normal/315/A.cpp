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
    long n,a[101],b[101],vis[101]={0},c=0,j,i;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i]>>b[i];
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(i!=j && a[j]==b[i])
    vis[j]=1;
    for(i=0;i<n;++i)
    if(!vis[i]) c++;
    cout<<c;
    return 0;
}