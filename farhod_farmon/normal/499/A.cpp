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

using namespace std;

int main()
{
    long long int a,b,c[51],d[51],i,j,cnt=0,f=1,g;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i]>>d[i];
    }
    for( i=1; i<=a; i++ ){
        g=( c[i]-f )/b;
        f+=g*b;
        cnt+=c[i]-f;
        cnt+=d[i]-c[i]+1;
        f=d[i]+1;
    }
    cout<<cnt;
    return 0;
}