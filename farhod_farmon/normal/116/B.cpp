#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j,cnt=0;
    char c[11][11];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]=='W' ){
                if( c[i+1][j]=='P' ){
                    cnt++;
                    continue;
                }
                if( c[i][j+1]=='P' ){
                    cnt++;
                    continue;
                }
                if( c[i-1][j]=='P' ){
                    cnt++;
                    continue;
                }
                if( c[i][j-1]=='P' ){
                    cnt++;
                    continue;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}