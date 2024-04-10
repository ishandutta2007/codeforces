#include<bits/stdc++.h>
using namespace std;
#define R(i,A,B) for(int i=A;i<=B;i++)
int n,m,b,M,a[511],dp[511][511],A;
int main()
{
    cin>>n>>m>>b>>M;
    R(i,1,n)cin>>a[i];
    dp[0][0]=1;
    R(_,1,n)R(i,1,m)R(j,a[_],b)dp[i][j]=(dp[i][j]+dp[i-1][j-a[_]])%M;
    R(i,0,b)A=(A+dp[m][i])%M;
    cout<<A<<endl;
    return 0;
}