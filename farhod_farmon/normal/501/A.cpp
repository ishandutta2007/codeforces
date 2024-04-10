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
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=max( a*3/10, a-a/250*c );
    b=max( b*3/10, b-b/250*d );
    if( a>b ){
        cout<<"Misha";
    }
    else if( b>a ){
        cout<<"Vasya";
    }
    else{
        cout<<"Tie";
    }
    return 0 ;
}