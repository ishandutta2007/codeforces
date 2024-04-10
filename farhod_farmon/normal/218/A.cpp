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
    int a,b[10001],i,k;
    cin>>a>>k;
    a=a*2+1;
    for( i=1; i<=a; i++ ) cin>>b[i];
    for( i=2; i<=a; i+=2 ){
        if( k && abs(b[i]-b[i-1])>1 && abs(b[i]-b[i+1])>1 ){
            b[i]--;
            k--;
        }
    }
    for( i=1; i<=a; i++ )cout<<b[i]<<" ";
}