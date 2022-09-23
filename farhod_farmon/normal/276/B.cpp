#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define si size
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
int main()
{
    string s;
    cin>>s;
    int a=s.size(),b,cnt=0,i;
    map < char, int > m;
    for( i=0; i<a; i++ )m[s[i]]++;
    for( i=0; i<a; i++ ){
        if( m[s[i]]%2!=0 )cnt++;
        m[s[i]]=0;
    }
    if( cnt==0 )cout<<"First";
    else if( a%2!=0 )cout<<"First";
    else cout<<"Second";
    return 0;
}