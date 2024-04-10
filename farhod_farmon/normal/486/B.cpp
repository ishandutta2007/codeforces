#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[101][101],i,j,h,k,d[101][101],f[101][101];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            d[i][j]=1;
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]==0 ){
                for( h=1; h<=max( a, b ); h++ ){
                    d[h][j]=0;
                    d[i][h]=0;
                }
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            f[i][j]=d[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( d[i][j]==1 ){
                for( h=1; h<=max( a, b ); h++ ){
                    f[i][h]=1;
                    f[h][j]=1;
                }
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( f[i][j]!=c[i][j] ){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}