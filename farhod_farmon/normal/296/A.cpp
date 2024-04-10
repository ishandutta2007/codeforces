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
    int a,b,c[10001]={},d=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b;
        c[b]++;
        d=max( d, c[b] );
    }
    if( d-1>a-d ){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}