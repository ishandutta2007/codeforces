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
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    fin
    fout
    int a[4]={},x,y,i;
    cin>>a[0];
    a[a[0]]=1;
    for( i=1; i<=3; i++ ){
        cin>>x>>y;
        swap( a[x], a[y] );
    }
    if( a[1]==1 )cout<<1;
    else if( a[2]==1 )cout<<2;
    else cout<<3;
}