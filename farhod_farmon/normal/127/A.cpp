#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x[101],y[101],i,j;
    float d,cnt=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>x[i]>>y[i];
    }
    for( i=1; i<a; i++ ){
        d=(x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]);
        cnt+=sqrt( d );
    }
    printf( "%.6f", cnt/50*b );
    return 0;
}