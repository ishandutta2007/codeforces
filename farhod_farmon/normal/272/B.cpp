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

int f( int x )
{
    if( x==0 )return 0;
    else if( x%2==0 ) return f(x>>1);
    else return f(x>>1)+1;
}

int main()
{
    long long int a,x,i,j,b[101]={},cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>x;
        b[f(x)]++;
    }
    for( i=0; i<=100; i++ ){
        cnt+=(b[i]*(b[i]-1)/2);
    }
    cout<<cnt;
    return 0;
}