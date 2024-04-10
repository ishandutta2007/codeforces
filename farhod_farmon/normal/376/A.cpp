#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long int a,hg1=0,hg2=0,i,j,g;
    cin>>s;
    a=s.size();
    for( i=0; i<a; i++ ){
        if( s[i]=='^' ){
            g=i;
            break;
        }
    }
    for( i=0; i<a; i++ ){
        if( s[i]=='^' ){
            break;
        }
        else if( s[i]=='=' ){
            continue;
        }
        hg1+=( ( s[i]-48 )*( g-i ) );
    }
    i++;
    for( ; i<a; i++ ){
        if( s[i]=='=' ){
            continue;
        }
        hg2+=( ( s[i]-48 )*( i-g ) );
    }
    if( hg1==hg2 ){
        cout<<"balance";
    }
    else if( hg1<hg2 ){
        cout<<"right";
    }
    else{
        cout<<"left";
    }
    return 0;
}