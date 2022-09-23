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
#include <stack>

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
    string c[9]={ "", "2", "3", "322", "5", "53", "7", "7222", "7332" };
    int a,b[111]={},i,j;
    string s;
    cin>>a>>s;
    for( i=0; i<=9; i++ )b[i]=0;
    for( i=0; i<s.size(); i++ ){
        if( s[i]=='0' || s[0]==1 )continue;
        for( j=0; j<c[s[i]-'1'].size(); j++ ){
            b[c[s[i]-'1'][j]-'0']++;
        }
    }
    for( i=9; i>=2; i-- ){
        for( j=1; j<=b[i]; j++ )cout<<i;
    }
    return 0;
}