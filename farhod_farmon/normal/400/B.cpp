
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
    int a,b,i,j,k,l,cnt=0;
    bool used[1001]={};
    char c[1001][1001],ans=true;
    vector < int > v,v1;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]=='S' )v.pb(j);
            if( c[i][j]=='G' )v1.pb(j);
            if( v.size()>v1.size() ){
                cout<<-1;
                return 0;
            }
            if( v.size()>0 && v1.size()>0 ){
                int x=v[v.size()-1],y=v1[v1.size()-1];
                v.p_b();
                v1.p_b();
                used[abs(x-y)]=true;
            }
        }
        if( v1.size()>0 ){
            cout<<-1;
            return 0;
        }
    }
    for( i=1; i<=b; i++ ) cnt+=used[i];
    cout<<cnt;
}