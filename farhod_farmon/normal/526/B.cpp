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
lli a,g=1,i,b[10001],d[10001],f=0,ans=0;
vector < lli > v;

void build( int x, int g, int sum )
{
    if( g==a ){
        v.pb(sum);
        return;
    }
    build( x*2, g+1, sum+b[x*2-1] );
    build( x*2+1, g+1, sum+b[x*2] );
}

void kor( int l, int r )
{
    if( l==r ){
        ans+=(f-v[l]);
        return;
    }
    bool b1=false;
    lli k=0;
    for( int j=l; j<=r; j++ ){
        k=max(k,v[j]);
        if( v[j]==f )b1=true;
    }
    k=f-k;
    for( int j=l; j<=r; j++ )v[j]+=k;
    ans+=k;
    int m=(l+r)/2;
    kor( l, m );
    kor( m+1, r );
}

int main()
{
    cin>>a;
    for( i=1; i<=a+1; i++ )g*=2;
    for( i=1; i<=g-2; i++ )cin>>b[i];
    build( 1, 0, 0 );
    for( i=0; i<v.size(); i++ )f=max(f,v[i]);
    kor( 0, v.size()-1 );
    cout<<ans;
}