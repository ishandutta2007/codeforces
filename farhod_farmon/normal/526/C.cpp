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
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    lli c,w1,w2,h1,h2,ans=0,i;
    cin>>c>>h1>>h2>>w1>>w2;
    for( i=1; i<=1000000; i++ ){
        if( w1*i<=c )ans=max( ans, h1*i+((c-w1*i)/w2)*h2 );
        if( w2*i<=c )ans=max( ans, h2*i+((c-w2*i)/w1)*h1 );
    }
    cout<<max( ans, max( (c/w1)*h1, (c/w2)*h2 ) );
}