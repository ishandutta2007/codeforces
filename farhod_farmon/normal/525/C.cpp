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
    lli a,b[100001],i,j,cnt=0;
    vector <lli> v;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    sort(b+1, b+a+1);
    for( i=a-1; i>=1; i-- ){
        if( b[i+1]-b[i]<=1 ){
            v.pb(b[i]);
            i--;
        }
    }
    if( v.size()%2 )v.pb(0);
    for( i=0; i<v.size(); i+=2 )cnt+=v[i]*v[i+1];
    cout<<cnt;
}