#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector < int > v;
    int a,i,d=0;
    cin>>a;
    while( a>0 ){
        if( a%7==0 ){
            for( i=1; i<=a/7; i++ ){
                v.push_back( 7 );
            }
            a=0;
            break;
        }
        else{
            if( a-4<0 ){
                break;
            }
            a-=4;
            v.push_back( 4 );
        }
    }
    if( a!=0 ){
        cout<<-1;
        return 0;
    }
    for( i=0; i<v.size(); i++ ){
        cout<<v[i];
    }
    return 0;
}