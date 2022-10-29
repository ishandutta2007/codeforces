#include <bits/stdc++.h>

using namespace std;
double dp[101][101][101][3]={0},t,a,b,c;
int main()
{
    cout.setf(ios::fixed);
    cout<<setprecision(13);
    long r,s,p,i,j,k;
    cin>>r>>s>>p;
    for(i=0;i<=100;++i)
        for(j=0;j<=100;++j)
    {
        if(i==0 && j==0) continue;
        dp[i][j][0][0]=1;dp[i][j][0][1]=0;dp[i][j][0][2]=0;
        dp[i][0][j][0]=0;dp[i][0][j][1]=0;dp[i][0][j][2]=1;
        dp[0][i][j][0]=0;dp[0][i][j][1]=1;dp[0][i][j][2]=0;
    }
    for(i=1;i<=r;i++)
        for(j=1;j<=s;++j)
            for(k=1;k<=p;++k)
    {
        t=i*j+j*k+i*k;a=i*k;b=j*i;c=j*k;
       dp[i][j][k][0]=(dp[i-1][j][k][0]*a)/t+(dp[i][j-1][k][0]*b)/t+(dp[i][j][k-1][0]*c)/t;
       dp[i][j][k][1]=(dp[i-1][j][k][1]*a)/t+(dp[i][j-1][k][1]*b)/t+(dp[i][j][k-1][1]*c)/t;
       dp[i][j][k][2]=(dp[i-1][j][k][2]*a)/t+(dp[i][j-1][k][2]*b)/t+(dp[i][j][k-1][2]*c)/t;
    }
    cout<<dp[r][s][p][0]<<" "<<dp[r][s][p][1]<<" "<<dp[r][s][p][2];
    return 0;
}