#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j,x,y,z,g,cnt=0,d=0;
    char c[51][51];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
            if( c[i][j]=='*' ){
                x=i;
                y=i;
                z=j;
                g=j;
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]=='*' ){
                x=min( x, i );
                y=max( y, i );
                z=min( z, j );
                g=max( g, j );
            }
        }
    }
    for( i=x; i<=y; i++ ){
        for( j=z; j<=g; j++ ){
            cout<<c[i][j];
        }
        cout<<endl;
    }
    return 0;
}