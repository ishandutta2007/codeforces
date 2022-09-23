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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "cowart.in", "r", stdin );
#define fout freopen( "cowart.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
vector < lli > v;
lli a;

void rec( lli x )
{
    lli g=0,y=x;
    while( y>0 ){
        g++;
        y/=10;
    }
    if( g>10 )return;
    v.pb(x);
    rec( x*10+4 );
    rec( x*10+7 );
}

int main()
{
    cin>>a;
    rec(4);
    rec(7);
    sort( v.begin(), v.end() );
    for( int i=0; i<v.size(); i++ ){
        if( v[i]==a ){
            cout<<i+1;
            return 0;
        }
    }
}