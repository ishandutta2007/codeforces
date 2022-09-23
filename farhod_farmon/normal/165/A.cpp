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
    int a,x[201],y[201],i,j,cnt=0,b=0,c=0,d=0,f=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>x[i]>>y[i];
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            if( i==j ){
                continue;
            }
            if( x[i]>x[j] && y[i]==y[j] ){
                b=1;
            }
            if( x[i]<x[j] && y[i]==y[j] ){
                c=1;
            }
            if( x[i]==x[j] && y[i]<y[j] ){
                d=1;
            }
            if( x[i]==x[j] && y[i]>y[j] ){
                f=1;
            }
        }
        cnt+=( f+d+c+b )/4;
        b=0;
        c=0;
        d=0;
        f=0;
    }
    cout<<cnt;
    return 0 ;
}