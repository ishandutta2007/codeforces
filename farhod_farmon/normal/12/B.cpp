#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pb push_back
#define si size
#define fi first
#define se second
#define lli long long int

using namespace std;
int main()
{
    vector < char > v;
    string t;
    char c[100];
    int a,b=0,i,j;
    cin>>c>>t;
    a=strlen(c);
    if( t.size()!=a ){
        cout<<"WRONG_ANSWER";
        return 0;
    }
    sort( c, c+a );
    for( i=0; i<a; i++ ){
        if( c[i]=='0' ){
            b++;
        }
        else{
            v.push_back( c[i] );
            break;
        }
    }
    for( j=0; j<b; j++ ){
        v.push_back( '0' );
    }
    i++;
    for( ; i<a; i++ ){
        v.push_back( c[i] );
    }
    for( i=0; i<v.si(); i++ ){
        if( v[i]!=t[i] ){
            cout<<"WRONG_ANSWER";
            return 0;
        }
    }
    cout<<"OK";
    return 0;
}