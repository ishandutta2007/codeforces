#include <bits/stdc++.h>
using namespace std;
int main()
{
    map < char, int > m;
    string s;
    int i;   
    cin>>s;
    for( i=0; i<s.size(); i++ ){
        m[s[i]]++;
    }
    if( m['7']>m['4'] ){
        cout<<7;
    }
    else if( m['4']>0 ){
        cout<<4;
    }
    else{
        cout<<-1;
    }
    return 0;
}