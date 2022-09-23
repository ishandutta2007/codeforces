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
    int a,b,i,j,cnt=0;
    char c[101][101],d[101];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
            if( c[i][j]>d[j] ){
                d[j]=c[i][j];
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]>=d[j] ){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return 0 ;
}