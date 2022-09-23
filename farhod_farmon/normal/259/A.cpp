#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    char c[10][10];
    for( i=1; i<=8; i++ ){
        for( j=1; j<=8; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=8; i++ ){
        for( j=1; j<=8; j++ ){
            if( c[i][j]==c[i][j+1] ){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}