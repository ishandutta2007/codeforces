#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d=0,f=0,i;
    cin>>a>>b;
    c=a+b;
    while( a>0 ){
        if( a%10!=0 ){
            d=d*10+(a%10);
        }
        a/=10;
    }
    while( b>0 ){
        if( b%10!=0 ){
            f=f*10+(b%10);
        }
        b/=10;
    }
    while( d>0 ){
        a=a*10+(d%10);
        d/=10;
    }
    while( f>0 ){
        b=b*10+(f%10);
        f/=10;
    }
    a+=b;
    f=0;
    while( c>0 ){
        if( c%10!=0 ){
            f=f*10+(c%10);
        }
        c/=10;
    }
    while( f>0 ){
        c=c*10+(f%10);
        f/=10;
    }
    if( c==a ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}