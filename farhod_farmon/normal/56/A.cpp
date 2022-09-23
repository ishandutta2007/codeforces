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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    map < string, int > m;
    int a,i,cnt=0,x;
    string s;
    cin>>a;
    m["ABSINTH"]=m["BEER"]=m["BRANDY"]=m["CHAMPAGNE"]=m["GIN"]=m["RUM"]=m["SAKE"]=m["TEQUILA"]=m["VODKA"]=m["WHISKEY"]=m["WINE"]=1;
    for( i=1; i<=a; i++ ){
        cin>>s;
        if( s[0]<65 ){
            x=0;
            for( int j=0; j<s.size(); j++ ) x=x*10+s[j]-48;
            if( x<18 )cnt++;

        }
        else if( m[s]==1 )cnt++;
    }
    cout<<cnt;
    return 0;
}