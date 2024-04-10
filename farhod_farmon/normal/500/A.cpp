#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <math.h>
#include <vector>
#include <map>

#define pb push_back
#define lli long long int
#define sc scanf
#define pr printf
#define cl clear
#define vlli vector < long long int >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >
#define fi first
#define se second

using namespace std;

int main()
{
    int a,b,c[100001],i;
    cin>>a>>b;
    for( i=1; i<a; i++ ){
        cin>>c[i];
    }
    i=1;
    while( i<b ){
        i=c[i]+i;
    }
    if( i==b ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}