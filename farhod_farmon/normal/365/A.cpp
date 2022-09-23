#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,j,cnt=0,d=0;
    char c,b;
    string s[101];
    map < char, int > m[101];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>s[i];
    }
    for( i=1; i<=a; i++ ){
        for( j=0; j<s[i].size(); j++ ){
            m[i][s[i][j]]++;
        }
    }
    for( i=1; i<=a; i++ ){
        for( c='0'; c<=b; c=c+1 ){
            if( m[i][c]==0 ){
                d=1;
            }
        }
        if( d!=1 ){
            cnt++;
        }
        d=0;
    }
    cout<<cnt;
    return 0;
}