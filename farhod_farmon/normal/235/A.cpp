#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,f,e,i,j,h,cnt=0;
    cin>>a;
    if( a<=5 ){
        if( a<=2 ){
            cout<<a;
        }
        else if( a>2 ){
            if( a==4 ){
                cout<<12;
            }
            else{
                cout<<a*(a-1)*(a-2);
            }
        }
        return 0;
    }
    for( i=a; i>=a-5; i-- ){
        for( j=a; j>=a-5; j-- ){
            for( h=a; h>=a-5; h-- ){
                d=i*j/( __gcd( i, j ) );
                f=d*h/( __gcd( d, h ) );
                cnt=max( f, cnt );
            }
        }
    }
    cout<<cnt;
    return 0;
}