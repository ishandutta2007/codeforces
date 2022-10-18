#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>

#define ll long long

using namespace std;

char str1[1000002]={0},str2[1000002]={0};

int dp[32005][36]={0};

bool powGr(int a,int b,int n)
{
    ll res=1;
    for(int i=0;i<b;i++)
    {
        res*=a;
        if (res>=n) return true;
    }
    return false;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b,n;
    cin >> a >> b >> n;
    /*if (a==1)
    {
        cout << "Missing\n";
        return 0;
    }*/
/*  if (b==1)
    {
        if ((n-a)%2==1)
            cout << "Stas\n";
        else cout << "Masha\n";
        if (a!=3) for(;;);
        return 0;
    }*/
    for(int i=32000;i>=a;i--)
    {
        for(int j=32;j>=b;j--)
        {
            if (i==1&&powGr(i+1,j,n))
            {
                dp[i][j]=-1;
                continue;
            }
            bool b1=powGr(i+1,j,n),b2=powGr(i,j+1,n);
            if (b1&&b2) dp[i][j]=0;
            else
                if (b1)
                {
                    if (dp[i][j+1]==0) dp[i][j]=1;
                    else if (dp[i][j+1]==-1) dp[i][j]=-1;
                    else dp[i][j]=0;
                }
                else
                    if (b2)
                    {
                        if (dp[i+1][j]==0) dp[i][j]=1;
                        else if (dp[i+1][j]==-1) dp[i][j]=-1;
                        else dp[i][j]=0;
                    }
                    else
                    {
                        if (dp[i][j+1]==0||dp[i+1][j]==0) dp[i][j]=1;
                        else if (dp[i][j+1]==-1||dp[i+1][j]==-1) dp[i][j]=-1;
                        else dp[i][j]=0;
                    }
        }
    }
    if (dp[a][b]==-1) cout << "Missing\n";
    else
    if (dp[a][b]==0) cout << "Stas\n";
    else cout << "Masha\n";
    return 0;
}