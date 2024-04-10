#include <bits/stdc++.h>
using namespace std;
int main()
{
    map < char, int > m;
    m['6']=1;
    m['7']=2;
    m['8']=3;
    m['9']=4;
    m['T']=5;
    m['J']=6;
    m['Q']=7;
    m['K']=8;
    m['A']=9;
    string s[3];
    char a;
    cin>>a>>s[1]>>s[2];
    if( s[1][1]==s[2][1] ){
        if( m[s[1][0]]>m[s[2][0]] ){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        return 0;
    }
    if( s[1][1]==a ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}