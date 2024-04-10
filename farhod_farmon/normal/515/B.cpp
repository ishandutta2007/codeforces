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
#define rep( a, b ) for( int i=a; i<=b; i++ )
#define tochniy_rep( a, b ) for( int i=min( a, b ); i<=max( a, b ); i++ )
#define fin freopen( "prefrev.txt", "r", stdin );
#define fout freopen( "prefrev.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    int a,b,c[101]={},d[101]={},cnt[3]={},i,j,k,l,m,n,x,y,g=0;
    cin>>a>>b;
    cin>>n;
    for( i=1; i<=n; i++ ){
        cin>>x;
        c[x]=1;
        cnt[0]++;
    }
    cin>>m;
    for( i=1; i<=m; i++ ){
        cin>>x;
        d[x]=1;
        cnt[1]++;
    }
    x=min(a,b);
    l=x*(abs(a-b))+1;
    l=l*x;
    for( i=0; i<50000; i++ ){
        x=i%a;
        y=i%b;
        if( c[x]==1 ){
            d[y]=1;
        }
        if( d[y]==1 ){
            c[x]=1;
        }
    }
    bool b1=true;
    for( i=0; i<max(a,b); i++ ){
        if( i<a && c[i]==0 ){
            b1=false;
            break;
        }
        if( i<b && d[i]==0 ){
            b1=false;
            break;
        }
    }
    if( b1 ){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}