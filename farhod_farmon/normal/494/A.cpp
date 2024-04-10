#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

#define pb push_back
#define lli long long int
#define sc scanf
#define pr printf
#define cl clear
#define fi first
#define se second
#define vlli vector < long long int >
#define vs vector < string >
#define vf vector < float >
#define vc vector < char >
#define vi vector < int >

using namespace std;
int main()
{
    map < char, int > m;
    string s;
    int a,b=0,c=0,g=0,h=0,i,j;
    cin>>s;
    a=s.size();
    for( i=0; i<a; i++ ){
        m[s[i]]++;
        m['(']-=m[')'];
        m[')']=0;
        if( m['#']>b ){
            b=m['#'];
            m['(']--;
        }
        if( m['(']<0 ){
            cout<<-1;
            return 0;
        }
    }
    for( i=a-1; i>=0; i-- ){
        if( s[i]=='#' ){
            break;
        }
        else if( s[i]=='(' ){
            g++;
        }
        else{
            g--;
        }
        if( g>0 ){
            cout<<-1;
            return 0;
        }
    }
    for( i=0; i<a; i++ ){
        if( s[i]=='#' ){
            c++;
            if( c!=m['#'] ){
                cout<<1<<endl;
            }
        }
        if( c==m['#'] ){
            cout<<m['(']+1<<endl;
            return 0;
        }
    }
    return 0;
}