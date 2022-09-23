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
    int a,b;
    cin>>a>>b;
    while( a<10000000 ){
        if( a%b==0 ){
            cout<<"Yes";
            return 0;
        }
        a+=a%b;
    }
    cout<<"No";
    return 0;
}