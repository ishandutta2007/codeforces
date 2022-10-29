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
string s[1001];
long n,m,i,j,ans=0,dp[1001][1001],visi[1001][1001]={0};
long dfs(long x,long y,char ch)
{
    long cur=0;
    if(x<0 || y<0 || x>n-1 || y>m-1) return 0;
    if(s[x][y]!=ch) return 0;
    if(visi[x][y] && dp[x][y]==-1) {cout<<"Poor Inna!";exit(0);}
    if(visi[x][y]) return dp[x][y];
    visi[x][y]=1;
    if(s[x][y]=='D')
    {
        cur=max(cur,dfs(x+1,y,'I'));
        cur=max(cur,dfs(x-1,y,'I'));
        cur=max(cur,dfs(x,y+1,'I'));
        cur=max(cur,dfs(x,y-1,'I'));
        return dp[x][y]=cur;
    }
    if(s[x][y]=='I')
    {
        cur=max(cur,dfs(x+1,y,'M'));
        cur=max(cur,dfs(x-1,y,'M'));
        cur=max(cur,dfs(x,y+1,'M'));
        cur=max(cur,dfs(x,y-1,'M'));
        return dp[x][y]=cur;
    }
    if(s[x][y]=='M')
    {
        cur=max(cur,dfs(x+1,y,'A'));
        cur=max(cur,dfs(x-1,y,'A'));
        cur=max(cur,dfs(x,y+1,'A'));
        cur=max(cur,dfs(x,y-1,'A'));
        return dp[x][y]=cur;
    }
    if(s[x][y]=='A')
    {
        cur=max(cur,dfs(x+1,y,'D'));
        cur=max(cur,dfs(x-1,y,'D'));
        cur=max(cur,dfs(x,y+1,'D'));
        cur=max(cur,dfs(x,y-1,'D'));
        return dp[x][y]=1+cur;
    }
}
int main()
{
    io
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    if(s[i][j]=='D' && visi[i][j]==0)
    ans=max(ans,dfs(i,j,'D'));
    if(ans==0) {cout<<"Poor Dima!";exit(0);}
    cout<<ans;
    return 0;
}