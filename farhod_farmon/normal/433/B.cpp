#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <vector>
#include <map>

#define pb push_back
#define lli long long int
#define st string
#define sc scanf
#define pr printf
#define cl clear
#define vlli vector < lli >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >
#define fi first
#define se second
#define pllilli pair < lli, lli >
#define pii pair < int, int >

using namespace std;
int main()
{
    int a,b,c[100001],d[100001],f[100001],i,type[100001];
    long long int dp[3][100001]={};
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>f[i];
        dp[1][i]=dp[1][i-1]+f[i];
    }
    cin>>b;
    for( i=1; i<=b; i++ ){
        cin>>type[i]>>c[i]>>d[i];
    }
    sort( f+1, f+a+1 );
    for( i=1; i<=a; i++ ){
        dp[2][i]=dp[2][i-1]+f[i];
    }
    for( i=1; i<=b; i++ ){
        cout<<dp[type[i]][d[i]]-dp[type[i]][c[i]-1]<<endl;
    }
    return 0;
}