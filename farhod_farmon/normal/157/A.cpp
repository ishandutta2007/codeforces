#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[31][31],i,j,h,cnt=0,d=0,f=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            cin>>b[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            for( h=1; h<=a; h++ ){
                d=d+b[h][j];
            }
            for( h=1; h<=a; h++ ){
                f+=b[i][h];
            }
            if( d>f ){
                cnt++;
            }
            d=0;
            f=0;
        }
    }
    cout<<cnt;
    return 0;
}