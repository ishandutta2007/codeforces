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
    bool b1=false;
    int a,i;
    string s[1001],t[1001];
    map < string, int > m;
    map < string, string > mt;
    vector < string > v,v1;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>s[i]>>t[i];
        m[s[i]]=1;
        mt[s[i]]=t[i];
    }
    for( i=1; i<=a; i++ ){
        while( m[s[i]]==1 ){
            if( b1==false ){
                b1=true;
                v.pb( s[i] );
            }
            m[s[i]]=0;
            s[i]=mt[s[i]];
        }
        if( b1==true ){
            v1.pb( s[i] );
        }
        b1=false;
    }
    cout<<v.size()<<endl;
    for( i=0; i<v.size(); i++ ){
        cout<<v[i]<<" "<<v1[i]<<endl;
    }
    return 0 ;
}