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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,m,a[1003][1003]={0},i,j,c=0,k,f,ff=0,fff=0,v[1003][1003]={0},x,y,d;
void dfs(long x,long y)
{
    if(v[x][y]) return;
    v[x][y]=1;
    if(a[x+1][y]) dfs(x+1,y);
    if(a[x][y+1]) dfs(x,y+1);
    if(a[x-1][y]) dfs(x-1,y);
    if(a[x][y-1]) dfs(x,y-1);
}
int main()
{
    io
    set < long > s;
    set < long > ::iterator it;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    cin>>a[i][j];
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if(!v[i][j] && a[i][j])
    {
        if(fff==0) dfs(i,j),fff=1;
        else {cout<<-1;exit(0);}
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if(a[i][j])
    {
        d=0;
        if(a[i+1][j]) d++;
        if(a[i][j+1]) d++;
        if(a[i-1][j]) d++;
        if(a[i][j-1]) d++;
        if(d%2) c++;
    }
    if(c>2) {cout<<-1;exit(0);}
    c=0;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        if(a[i][j]) c++;
        else s.insert(c),c=0;
        s.insert(c);
        c=0;
    }
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        if(a[j][i]) c++;
        else s.insert(c),c=0;
        s.insert(c);
        c=0;
    }
    if(s.find(0)!=s.end()) s.erase(s.find(0));
    if(s.find(1)!=s.end()) s.erase(s.find(1));
    if(s.empty()) {cout<<-1;exit(0);}
    for(k=2;k<=n;++k)
    {
        f=1;
        for(it=s.begin();it!=s.end();it++)
        if((*it-1)%k!=0) {f=0;break;}
        if(f) cout<<k<<" ",ff=1;
    }
    if(!ff) cout<<-1;
    return 0;
}