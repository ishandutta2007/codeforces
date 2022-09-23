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
    int n,p,k,a,b,i,j,cnt=0;
    cin>>n>>p>>k;
    if( p-k<=1 ){
        a=1;
        b=p+k;
    }
    else{
        cout<<"<< ";
        a=p-k;
        b=p+k;
    }
    if( b>n ){
        b=n;
    }
    for( i=a; i<=b; i++ ){
        if( i==p ){
            cout<<"("<<i<<") "; 
        }
        else{
            cout<<i<<" ";
        }
    }   
    if( b!=n ){
        cout<<">>";
    }
    return 0 ;
}