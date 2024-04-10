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
#include <queue>

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
#define fin freopen( "ride.txt", "r", stdin );
#define fout freopen( "ride.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    string s;
    int i;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
        if( s[i]>'4'){
            if( s[i]!='9' || s[i]=='9' && i>0 ){
                int x=s[i]-48;
            x=9-x;
            s[i]=x+48;
            }
        }
    }
    cout<<s;
    return 0;
}