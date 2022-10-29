#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long n,i,j,visi[51][51]={0},dx,dy;
vector < pair < long , long > > v;
string s[51],a[102];
long check(long x,long y)
{
    long i,j,f=0;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(s[i][j]=='o')
    if(i+x>=0 && i+x<n && j+y>=0 && j+y<n)
    {
        if(s[i+x][j+y]=='.') return 0;
        else f=1;
    }
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(s[i][j]=='o')
    if(i+x>=0 && i+x<n && j+y>=0 && j+y<n)
    if(s[i+x][j+y]=='x')
    visi[i+x][j+y]=1;
    return f;
}
int main()
{
    long g=0;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(i=-n+1;i<n;++i)
    for(j=-n+1;j<n;++j)
    if(check(i,j))
    v.pb({i,j});
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(s[i][j]=='x') g=1;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(s[i][j]=='x' && visi[i][j]==0) {cout<<"NO";exit(0);}
    for(i=0;i<2*n-1;++i)
    for(j=0;j<2*n-1;++j)
    a[i].pb('.');
    for(i=0;i<v.size();++i)
    {
        dx=v[i].first;
        dy=v[i].second;
        a[n-1+dx][n-1+dy]='x';
    }
    a[n-1][n-1]='o';
    if(v.size()==0 && g==1) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    for(i=0;i<2*n-1;++i)
    cout<<a[i]<<endl;
    return 0;
}