#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[51][51],i,j,ans;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]==1 && ( i==1 || j==1 || i==a || j==b ) ){
                cout<<2;
                return 0;
            }
        }
    }
    cout<<4;
    return 0;
}