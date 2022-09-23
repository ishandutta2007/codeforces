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
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, i, j, ans, b[2000011];

int main ()
{
    sc("%I64d", &a);
    for( i = 1; i <= a; i++ )sc("%I64d", &b[i]);
    sort( b + 1, b + a + 1 );
    for( i = a; i >= 1; i-- )b[i] += b[i + 1];
    i = 1;
    while(i <= a){
        ans += b[a - i + 1];
        i *= 4;
    }
    pr("%I64d", ans);
}