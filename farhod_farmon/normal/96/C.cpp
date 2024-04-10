#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define rep( a, b ) for( int i=a; i<=b; i++ )
#define tochniy_rep( a, b ) for( int i=min( a, b ); i<=max( a, b ); i++ )
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    //97
    //fin
    //fout
    string s[101],t,v,ans;
    int a,b,d,i,j,h,k=0,used[10001]={};
    cin>>a;
    char c;
    for( i=1; i<=a; i++ ){
        cin>>s[i];
        for( j=0; j<s[i].size(); j++ ){
            if( s[i][j]<97 )s[i][j]+=32;
        }
    }
    cin>>v>>c;
    ans=v;
    for( j=0; j<v.size(); j++ ){
            if( v[j]<97 )v[j]+=32;
        }
    for( i=0; i<v.size(); i++ ){
        for( j=1; j<=a; j++ ){
            k=0;
            for( h=0; h<s[j].size(); h++ ){
                if( s[j][k]==v[i+h] )k++;
            }
            if( k==s[j].size() ){
                for( h=0; h<s[j].size(); h++ )used[h+i]=1;
            }
        }
    }
    if( c<97 )c+=32;
    for( i=0; i<v.size(); i++ ){
        if( used[i]==1 ){
            if( v[i]==c ){
                if( 'A'==c || 'a'==c )v[i]='b';
                else v[i]='a';
            }
            else v[i]=c;
        }
    }
    for( i=0; i<v.size(); i++ ){
        if( ans[i]<97 )v[i]-=32;;
    }
    cout<<v;
    return 0;
}