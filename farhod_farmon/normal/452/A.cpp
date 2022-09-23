#include <bits/stdc++.h>
using namespace std;
int main()
{
    map < int, string > m;
    int a,i,cnt=0,t=0,d;
    string s,s1;

        m[0]="jolteon";
        m[1]="flareon";
        m[2]="umbreon";
        m[3]="leafeon";
        m[4]="glaceon";
        m[5]="sylveon";

    cin>>a>>s;
    if( a==8 ){
        cout<<"vaporeon\n";
        return 0;
    }
    if( a==6 ){
        cout<<"espeon\n";
        return 0;
    }
    for( int j=0; j<=5; j++ ){
        for( i=0; i<=a; i++ ){
            if( m[j][i]==s[i] ){
                t++;
            }
        }
        if( t>cnt ){
            cnt=t;
            s1=m[j];
        }
        t=0;
    }
    cout<<s1;
    return 0;
}