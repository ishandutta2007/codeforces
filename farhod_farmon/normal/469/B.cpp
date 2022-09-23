#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

#define pb push_back
#define lli long long int
#define sc scanf
#define pr printf
#define cl clear
#define fi first
#define se second
#define vlli vector < long long int >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >

using namespace std;
int main()
{
    int b1[1001]={0};
    int p,q,l,r,i,j,h,a[51],b[51],c[51],d[51],cnt=0;
    cin>>p>>q>>l>>r;
    for( i=1; i<=p; i++ ){
        cin>>a[i]>>b[i];
    }
    for( i=1; i<=q; i++ ){
        cin>>c[i]>>d[i];
    }
    for( i=1; i<=q; i++ ){
        if( d[i]<c[i] ){
            swap( d[i], c[i] );
        }
    }
    for( i=1; i<=p; i++ ){
        if( b[i]<a[i] ){
            swap( a[i], b[i] );
        }
    }
    for( i=l; i<=r; i++ ){
        for( j=1; j<=q; j++ ){
            for( h=1; h<=p; h++ ){
                if( ( d[j]+i>=a[h] && c[j]+i>=a[h] && d[j]+i<=b[h] && c[j]+i<=b[h] ) || ( c[j]+i<=a[h] && c[j]+i<=b[h] && d[j]+i>=a[h] && d[j]+i>=b[h] ) || ( c[j]+i>=a[h] && c[j]+i<=b[h] && d[j]+i>=a[h] && d[j]+i>=b[h] ) || ( d[j]+i>=a[h] && d[j]+i<=b[h] && c[j]+i<=b[h] && c[j]+i<=a[h] ) ){
                    b1[i]=1;
                    break;
                }
            }
        }
    }

    for( i=l; i<=r; i++ ){
        cnt+=b1[i];
    }
    cout<<cnt;
    return 0;
}