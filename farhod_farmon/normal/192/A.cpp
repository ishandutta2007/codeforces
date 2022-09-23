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
    lli a,i=1,j,k;
    vector < lli > v;
    cin>>a;
    while( i*(i+1)/2<=a ){
        v.pb(i*(i+1)/2);
        i++;
    }
    for( i=0; i<v.size(); i++ ){
        k=a-v[i];
        lli l=0,r=v.size()-1;
        while( l<r ){
            lli m=(l+r)/2;
            if( v[m]<k )l=m+1;
            else r=m;
        }
        if( v[l]==k ){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}