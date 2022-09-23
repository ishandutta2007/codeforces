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
    long long int a,b,dp[100001]={},c[100001]={},i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b;
        c[b]++;
    }
    dp[1]=c[1];
    for( i=2; i<=100000; i++ ){
        dp[i]=max( dp[i-1], dp[i-2]+( i*c[i] ) );
    }
    cout<<dp[100000];
    return 0;
}