#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[3],t;
    int a,b,i,j,g=1,d;
    cin>>s[0]>>t;
    d=t.size();
    for( i=0; i<s[0].size(); i++ ){
        if( s[0][i]=='|' ){
            g++;
            continue;
        }
        s[g]+=s[0][i];
    }
    g=0;
    a=s[1].size();
    b=s[2].size();
    while( g<d ){
        if( a<b ){
            s[1]+=t[g];
        }
        else{
            s[2]+=t[g];
        }
        g++;
        a=s[1].size();
        b=s[2].size();
    }
    if( a==b ){
        cout<<s[1]<<"|"<<s[2];
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}