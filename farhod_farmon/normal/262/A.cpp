#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,cnt=0,d=0;
    string s;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>s;
        for( int j=0; j<s.size(); j++ ){
            if( s[j]=='4' || s[j]=='7' ){
                d++;
            }
        }
        if( d<=b ){
            cnt++;
        }
        d=0;
    }
    cout<<cnt;
    return 0;
}