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
    int a,b,i,j,cnt=0,g,f;
    string s[3001],s1[3001],t[3001];
    map < string, string > m;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>s[i]>>s1[i];
        m[s[i]]=s1[i];
    }
    for( i=1; i<=a; i++ ){
        cin>>t[i];
    }
    for( i=1; i<=a; i++ ){
        if( m[t[i]].size()<t[i].size() ){
            cout<<m[t[i]]<<" ";
        }
        else{
            cout<<t[i]<<" ";
        }
    }
    return 0;
}