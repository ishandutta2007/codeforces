#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,c,b[10001],i;
    float cnt=0,f,d;
    cin>>a>>c;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    b[0]=0;
    b[a+1]=c;
    sort( b,b+a+2 );
    d=c-b[a];
    cnt=b[1];
    cnt=max( cnt,d );
    for( i=1; i<=a+1; i++ ){
        f=b[i+1]-b[i];
        f=f/2;
        cnt=max( cnt,f );
    }
    printf( "%.9f",cnt );
    return 0;
}