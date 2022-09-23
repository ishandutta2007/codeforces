#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,i,j,cnt=0,dp[51]={};
    cin>>a;
    char c[a+1];dp[1]=1;
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=2; i<=a; i++ )dp[i]=dp[i-1]*2;
    for( i=1; i<=a; i++ ){
        if( c[i]=='B' )cnt+=dp[i];
    }
    cout<<cnt;
    return 0;
}