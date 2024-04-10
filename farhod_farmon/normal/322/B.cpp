#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,cnt=0,d;
    scanf( "%d%d%d", &a, &b, &c );
    d=min( a, min( b, c ) );
    if( d==0 ){
        cout<<a/3+b/3+c/3;
        return 0;
    }
    if( d==a ){
        if( ( b-( d-1 ) )%3==0 && ( c-( d-1 ) )%3==0 ){
            d--;
        }
    }
    if( d==b ){
        if( ( a-( d-1 ) )%3==0 && ( c-( d-1 ) )%3==0 ){
            d--;
        }
    }
    if( d==c ){
        if( ( b-( d-1 ) )%3==0 && ( a-( d-1 ) )%3==0 ){
            d--;
        }
    }
    a-=d;
    b-=d;
    c-=d;
    cnt=a/3+b/3+c/3+d;
    printf( "%d", cnt );
    return 0;
}