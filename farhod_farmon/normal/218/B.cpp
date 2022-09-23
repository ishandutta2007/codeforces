#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[10001],i,j,maxn=0,minn=0,f,d[10001],g=1;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>c[i];
        d[i]=c[i];
    }
    sort( c+1, c+b+1 );
    sort( d+1, d+b+1 );
    while( a>0 ){
        a--;
        sort( d+1, d+b+1 );
        sort( c+1, c+b+1 );
        if( d[g]==0 ){
            g++;
        }
        maxn+=c[b];
        c[b]--;
        minn+=d[g];
        d[g]--;
    }
    cout<<maxn<<" "<<minn;
    return 0;
}