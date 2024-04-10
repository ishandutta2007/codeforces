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
    int  a,b,x,y,c[100001],d[100001],i,j;
    vector < int > v,v1;
    cin>>a>>b>>x>>y;
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=1; i<=b; i++ )cin>>d[i];
    i=j=1;
    while( i<=a && j<=b ){
        int x1=c[i]-x,y1=c[i]+y;
        if( x1<=d[j] && d[j]<=y1 ){
            v.pb( i );
            v1.pb( j );
            i++;
            j++;
        }
        else if( d[j]<y1 ) j++;
        else i++;
    }
    cout<<v.size()<<endl;
    for( i=0; i<v.size(); i++ )cout<<v[i]<<" "<<v1[i]<<endl;
}