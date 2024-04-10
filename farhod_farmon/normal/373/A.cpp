#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,j;
    char c[6][6];
    map < char, int > m;
    cin>>a;
    for( i=1; i<=4; i++ ){
        for( j=1; j<=4; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=4; i++ ){
        for( j=1; j<=4; j++ ){
            if( c[i][j]!='.' ){
                m[c[i][j]]++;
                if( m[c[i][j]]>a*2 ){
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    cout<<"YES";
    return 0;
}