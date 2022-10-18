#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,pos[100001][2];
string s;
int main()
{
    cin>>n>>m;
    if(n==m)
    {
        puts("tokitsukaze");
        return 0;
    }
    cin>>s;
    s=" "+s;
    pos[1][0]=1;
    pos[n][1]=n;
    for(int i=2;i<n;++i)
        pos[i][0]=s[i]==s[i-1]? pos[i-1][0]:i;
    for(int i=n-1;i>=2;--i)
        pos[i][1]=s[i]==s[i+1]? pos[i+1][1]:i;
    if(pos[m+1][1]==n||pos[n-m][0]==1)
    {
        puts("tokitsukaze");
        return 0;
    }
    for(int i=2;i+m-1<n;++i)
        if(s[i-1]==s[i+m]&&pos[i-1][0]==1&&pos[i+m][1]==n)
        {
            puts("tokitsukaze");
            return 0;
        }
    if(m<<1<n)
    {
        puts("once again");
        return 0;
    }
    for(int i=2;i+m-1<n;++i)
        if(pos[i-1][0]!=1||pos[i+m][1]!=n)
        {
            puts("once again");
            return 0;
        }
    puts("quailty");
    return 0;
}