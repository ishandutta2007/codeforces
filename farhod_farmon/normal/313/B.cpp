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
    int a,b[100001],dp[100001]={},c[100001]={},i;
    string s;
    cin>>s;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i]>>c[i];
    }
    dp[1]=0;
    for( i=1; i<s.size(); i++ ){
        dp[i+1]=dp[i];
        if( s[i]==s[i-1] ){
            dp[i+1]++;
        }
    }
    for( i=1; i<=a; i++ ){
        cout<<dp[c[i]]-dp[b[i]]<<endl;
    }
    return 0;
}