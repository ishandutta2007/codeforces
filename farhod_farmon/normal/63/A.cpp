#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i;
    string s[101],w[101];
    vector < string > v;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>s[i]>>w[i];
    }
    for( i=1; i<=a; i++ ){
        if( w[i]=="rat" ){
            v.push_back( s[i] );
        }
    }
    for( i=1; i<=a; i++ ){
        if( w[i]=="woman" || w[i]=="child" ){
            v.push_back( s[i] );
        }
    }
    for( i=1; i<=a; i++ ){
        if( w[i]=="man" ){
            v.push_back( s[i] );
        }
    }
    for( i=1; i<=a; i++ ){
        if( w[i]=="captain" ){
            v.push_back( s[i] );
        }
    }
    for( i=0; i<a; i++ ){
        cout<<v[i]<<endl;
    }
    return 0;
}