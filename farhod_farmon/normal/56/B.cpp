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
int main()
{
    int a,b[1001],x=0,y=0,cnt=0,i,j,c[1001];
    cin>>a;
    bool b1=false,b2=true;
    y=a;
    for( i=1; i<=a; i++ ) cin>>b[i];
    for( i=1; i<a; i++ ){
        if( b[i]>b[i+1] && !b1 ){
            b1=true;
            x=i;
        }
        if( b[i]<b[i+1] && b1 ){
            b1=false;
            cnt++;
            y=i;
        }
    }
    if( cnt>1 || x==0 || b[y]<b[x-1] )cout<<"0 0";
    else cout<<x<<" "<<y;
    return 0;
}