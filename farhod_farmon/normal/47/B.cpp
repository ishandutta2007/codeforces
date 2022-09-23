#include <bits/stdc++.h>
using namespace std;
int main()
{
    map < char, int > m;
    string s[4];
    int i,a[4];
    cin>>s[1]>>s[2]>>s[3];
    if( s[1][1]=='>' ){
        m[s[1][0]]++;
        m[s[1][2]]--;
    }
    else{
        m[s[1][0]]--;
        m[s[1][2]]++;
    }
    if( s[2][1]=='>' ){
        m[s[2][0]]++;
        m[s[2][2]]--;
    }
    else{
        m[s[2][0]]--;
        m[s[2][2]]++;
    }
    if( s[3][1]=='>' ){
        m[s[3][0]]++;
        m[s[3][2]]--;
    }
    else{
        m[s[3][0]]--;
        m[s[3][2]]++;
    }
    m['A']+=2;
    m['B']+=2;
    m['C']+=2;
    if( m['A']==0 || m['B']==0 || m['C']==0 ){
        a[1]=m['A'];
        a[2]=m['B'];
        a[3]=m['C'];
        sort( a+1, a+4 );
        if( a[1]==m['A'] ){
            cout<<"A";
        }
        else if( a[1]==m['B'] ){
            cout<<"B";
        }
        else{
            cout<<"C";
        }
        if( a[2]==m['A'] ){
            cout<<"A";
        }
        else if( a[2]==m['B'] ){
            cout<<"B";
        }
        else{
            cout<<"C";
        }
        if( a[3]==m['A'] ){
            cout<<"A";
        }
        else if( a[3]==m['B'] ){
            cout<<"B";
        }
        else{
            cout<<"C";
        }
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}