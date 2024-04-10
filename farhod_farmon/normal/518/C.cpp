
#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define fi first
#define se second
#define rep( a, b ) for( int i=a; i<=b; i++ )
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define tochniy_rep( a, b ) for( int i=min( a, b ); i<=max( a, b ); i++ )
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    long long int a,b,c[100001],d[100001],i,j,k,l,m,n,g[100001],in[100001],cnt=0;
    cin>>a>>b>>k;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
        g[c[i]]=i;
        in[i]=c[i];
    }
    for( i=1; i<=b; i++ ){
        cin>>d[i];
        cnt+=((g[d[i]]-1)/k)+1;
        if( g[d[i]]!=1 ){
            l=g[d[i]];
            m=in[l-1];
            g[d[i]]=l-1;
            g[m]=l;
            in[l-1]=d[i];
            in[l]=m;
        }
    }
    cout<<cnt;
    return 0;
}