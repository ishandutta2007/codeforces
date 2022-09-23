#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define lli long long int
#define sc scanf
#define pr printf

using namespace std;
int main()
{
    int a,b,i,j;
    char c[105][105];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    c[a+1][1]=c[a][1]-1;
    for( i=1; i<=a; i++ ){
        for( j=1; j<b; j++ ){
            if( c[i][j]!=c[i][j+1] ){
                cout<<"NO";
                return 0;
            }
        }
        if( c[i][1]==c[i+1][1] ){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}