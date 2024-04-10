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
long t,n,k,i,j,a[5][104]={0},x,y,f=0,visi[5][104];
void dfs(long x,long y)
{
    if(visi[x][y] || a[x][y]==0) return;
    visi[x][y]=1;
    if(y>=n) {f=1;return;}
    if(f) return;
    if(a[x][y+1] && a[x][y+2] && a[x][y+3]) dfs(x,y+3);
    if(f) return;
    if(a[x-1][y+1] && a[x-1][y+2] && a[x-1][y+3] && a[x][y+1]) dfs(x-1,y+3);
    if(f) return;
    if(a[x+1][y+1] && a[x+1][y+2] && a[x+1][y+3] && a[x][y+1]) dfs(x+1,y+3);
}
int main()
{
    io
    cin>>t;
    string s;
    while(t--)
    {
        cin>>n>>k;
        memset(a,0,sizeof(a));
        memset(visi,0,sizeof(visi));
        for(i=1;i<4;++i)
        for(j=1;j<=n+2;++j)
        a[i][j]=1;
        for(i=1;i<=3;++i)
        {
            cin>>s;
            for(j=1;j<=n;++j)
            if(s[j-1]!='s')
            a[i][j]=!isalpha(s[j-1]);
            else x=i,y=j,a[i][j]=1;
        }
        f=0;
        dfs(x,y);
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}