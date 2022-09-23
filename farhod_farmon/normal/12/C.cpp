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
    map < string, int > m,m1;
    int a,b,c[101],i,j,minn=0,maxn=0,d[101],g=0,h,k=1;
    string s[101];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    for( i=1; i<=b; i++ ){
        cin>>s[i];
        m[s[i]]++;
        if( m[s[i]]==1 ){
            g++;
            m1[s[i]]=g;
            d[g]=m[s[i]];
        }
        else{
            d[m1[s[i]]]=m[s[i]];
        }
    }
    sort( c+1, c+a+1 );
    sort( d+1, d+g+1 );
    h=a;
    while( g>0 ){
        minn+=d[g]*c[k];
        maxn+=d[g]*c[h];
        k++;
        h--;
        g--;
    }
    cout<<minn<<" "<<maxn;
    return 0;
}