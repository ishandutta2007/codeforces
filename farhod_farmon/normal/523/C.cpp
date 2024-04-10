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
    int i,g,x=0,y=0;
    cin>>s>>t;
    g=s.size()-1;
    for( i=t.size()-1; i>=0; i-- ){
        if( t[i]==s[g] )g--;
        if( g<0 ){
            x=i;
            break;
        }
    }
    g=0;
    for( i=0; i<t.size(); i++ ){
        if( t[i]==s[g] )g++;
        if( g==s.size() ){
            y=i;
            break;
        }
    }
    if( x-y<0 )cout<<0;
    else cout<<abs(x-y);
}