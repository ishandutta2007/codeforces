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
int ans,i,j,a,b,t[100001],d;
int main()
{
    cin>>a>>b>>t[0]>>d;
    t[1]=a;
    for( i=2; i<=t[0]; i++ ){
        int g=0;
        for( j=-d; j<=d; j++ ){
            if( (t[i-1]+j)-(t[0]-i)*d<=b ) t[i]=t[i-1]+j;
        }
    }
    for( i=1; i<=t[0]; i++ )ans+=t[i];
    cout<<ans;
}