#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define lli long long int
#define sc scanf
#define pr printf

using namespace std;
int main()
{
    lli cnt=0;
    lli a,b,i,j,d;
    pair < lli, lli > p[30];
    cin>>a>>b;
    d=b;
    for( i=1; i<=b; i++ ){
        cin>>p[i].se>>p[i].fi;
    }
    sort( p+1, p+b+1 );
    while( a>0 ){
        if( a>=p[d].se ){
            a-=p[d].se;
            cnt+=p[d].fi*p[d].se;
            d--;
        }
        else{
            cnt+=p[d].fi*a;
            a=0;
        }
        if( d==0 ){
            break;
        }
    }
    cout<<cnt;
    return 0;
}