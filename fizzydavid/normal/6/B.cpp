#include<iostream>
#include<set>
#include<cstdlib>
using namespace std;
set<char>a;
int n,m,sum,i,j,k,l;
char c,b[110][110];
int main()
{
    for(i=0;i<110;i++)for(j=0;j<110;j++)b[i][j]='.';
    cin>>n>>m>>c;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>b[i][j];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        if(b[i][j]==c)
        {
            a.insert(b[i-1][j]);a.insert(b[i+1][j]);a.insert(b[i][j-1]);a.insert(b[i][j+1]);a.insert(b[i][j]);
            if(b[i-1][j]=='.'||b[i+1][j]=='.'||b[i][j-1]=='.'||b[i][j+1]=='.')sum=-1;
        }
    }
    cout<<sum+a.size()-1;
    return 0;
}