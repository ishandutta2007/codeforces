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
#define fin freopen( "skidesign.in", "r", stdin );
#define fout freopen( "skidesign.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    lli n,a,b,l,r,m,i,g=0;
    cin>>n>>a>>b;
    if( a>b ){
        swap(a,b);
        g=1;
    }
    l=a*b;
    r=999999999999999999999ll;
    while( l!=r ){
        m=( l+r )/2;
        if( m>=n*6 )r=m;
        else l=m+1;
    }
    while(1){
        for( i=a; i*i<=l; i++ ){
            if( l%i==0 && l/i>=b ){
                cout<<l<<endl;
                if( !g )cout<<i<<" "<<l/i;
                else cout<<l/i<<" "<<i;
                return 0;
            }
        }
        l++;
    }
}