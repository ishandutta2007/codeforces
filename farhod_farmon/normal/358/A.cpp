#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[1001],c[1001],d[1001],f;
    long long i,j;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if( i<a ){
            c[i]=b[i];
        }
    }
    for( i=2; i<=a; i++ ){
        d[i-1]=b[i];
    }
    for( i=1; i<a; i++ ){
        if( c[i]>d[i] ){
            swap( c[i], d[i] );
        }
    }
    for( i=1; i<a; i++ ){
        for( j=1; j<a; j++ ){
            if( i!=j && c[j]>c[i] && c[j]<d[i] && d[j]>d[i] ){
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}