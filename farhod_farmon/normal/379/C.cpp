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
    int a,i,j,k,l,n;
    pair < int, int > p[300001],p1[300001];
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>p[i].fi;
        p[i].se=i;
    }
    sort( p+1, p+a+1 );
    p1[0].se=0;
    for( i=1; i<=a; i++ ){
        if( p[i].fi>p1[i-1].se )p1[i].se=p[i].fi;
        else p1[i].se=p1[i-1].se+1;
        p1[i].fi=p[i].se;
    }
    sort( p1+1, p1+a+1 );
    for( i=1; i<=a; i++ )cout<<p1[i].se<<" ";
}