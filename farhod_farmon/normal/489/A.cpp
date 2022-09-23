#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector < long long int > x,y;
    long long int a,b[30001],i,j,cnt=0,c[30001],d,f;
    bool b1=false;
    cin>>a;
    for( i=0; i<a; i++ ){
        cin>>b[i];
        c[i]=b[i];
    }
    b[a]=9999999999;
    sort( c, c+a );
    farhod:
    for( i=0; i<a; i++ ){
        for( j=0; j<a; j++ ){
            if( c[i]==b[j] && b[j]!=c[j] ){
                x.push_back( i );
                y.push_back( j );
                swap( b[i], b[j] );
                break;
            }
        }
    }
    for( i=0; i<a; i++ ){
        if( b[i]>b[i+1] ){
            goto farhod;
        }
    }
    cout<<x.size()<<endl;
    for( i=0; i<x.size(); i++ ){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
    return 0;
}