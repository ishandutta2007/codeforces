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
    int a,b,i,j,k,c[1001];
    string s;
    cin>>a>>s;
    for( i=0; i<a; i++ ){
        if( s[i]<97 ){
            c[s[i]+32]++;
        }
        else c[s[i]]++;
    }
    for( char d='a'; d<='z'; d++ ){
        if( c[d]==0 ){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}