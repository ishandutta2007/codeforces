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
    bool used[100001]={};
    int n,m,i,j,a[100001],b[100001],x[100001],y[100001],c[1001][1001]={},h=0,k=0;
    cin>>n>>m;
    for( i=1; i<=n; i++ ) cin>>x[i]>>y[i];
    for( i=1; i<=m; i++ ){
        cin>>a[i]>>b[i];
        c[a[i]][b[i]]++;
    }
    for( i=1; i<=n; i++ ){
        if( c[x[i]][y[i]]>0 ){
            h++;
            k++;
            c[x[i]][y[i]]--;
            used[i]=1;
        }
    }
    for( i=1; i<=n; i++ ){
        if( used[i]==0 ){
            for( j=1; j<=1000; j++ ){
                if( c[j][y[i]]>0 ){
                    h++;
                    c[j][y[i]]--;
                    break;
                }
            }
        }
    }
    cout<<h<<" "<<k;
    return 0;
}