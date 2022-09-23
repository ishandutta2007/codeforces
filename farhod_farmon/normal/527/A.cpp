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
#define fin freopen( "skidesign.in", "r", stdin );
#define fout freopen( "skidesign.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    lli a,b,cnt=0,x;
    cin>>a>>b;
    while( a!=0 ){
        if( a<b )swap(a,b);
        x=a/b;
        cnt+=x;
        a=a%b;
    }
    cout<<cnt+a*b;
}