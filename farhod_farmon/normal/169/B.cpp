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
    string s,t;
    int i,j,b[10]={},g=9;
    cin>>s>>t;
    for( i=0; i<t.size(); i++ ){
        b[t[i]-48]++;
    }
    for( i=0; i<s.size(); i++ ){
        while( b[g]==0 && g>0 ) g--;
        if( s[i]-48<g && g!=0 ){
            s[i]=g+48;
            b[g]--;
        }
    }
    cout<<s;
    return 0;
}