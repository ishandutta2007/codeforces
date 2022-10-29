#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long n,m,i,j;
char a[2002][2002];
void dfs(long i,long j)
{
    if(((a[i+1][j]=='.') + (a[i-1][j]=='.') + (a[i][j+1]=='.') + (a[i][j-1]=='.') )==1)
    {
        if(a[i+1][j]=='.')
        {
            a[i][j]='^';
            a[i+1][j]='v';
            if(a[i+2][j]=='.') dfs(i+2,j);
            if(a[i+1][j+1]=='.') dfs(i+1,j+1);
            if(a[i+1][j-1]=='.') dfs(i+1,j-1);
        }
        if(a[i-1][j]=='.')
        {
            a[i][j]='v';
            a[i-1][j]='^';
            if(a[i-2][j]=='.') dfs(i-2,j);
            if(a[i-1][j+1]=='.') dfs(i-1,j+1);
            if(a[i-1][j-1]=='.') dfs(i-1,j-1);
        }
        if(a[i][j+1]=='.')
        {
            a[i][j]='<';
            a[i][j+1]='>';
            if(a[i][j+2]=='.') dfs(i,j+2);
            if(a[i-1][j+1]=='.') dfs(i-1,j+1);
            if(a[i+1][j+1]=='.') dfs(i+1,j+1);
        }
        if(a[i][j-1]=='.')
        {
            a[i][j]='>';
            a[i][j-1]='<';
            if(a[i][j-2]=='.') dfs(i,j-2);
            if(a[i-1][j-1]=='.') dfs(i-1,j-1);
            if(a[i+1][j-1]=='.') dfs(i+1,j-1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    cin>>a[i][j];
    for(i=0;i<=n;++i)
    {
        a[i][m+1]='*';
        a[i][0]='*';
    }
    for(i=0;i<=m;++i)
    {
        a[n+1][i]='*';
        a[0][i]='*';
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    {
        if(a[i][j]=='.')
        dfs(i,j);
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    if(a[i][j]=='.') {cout<<"Not unique";exit(0);}
    for(i=1;i<=n;++i)
    {for(j=1;j<=m;++j)
    cout<<a[i][j];
    cout<<endl;}
    return 0;
}