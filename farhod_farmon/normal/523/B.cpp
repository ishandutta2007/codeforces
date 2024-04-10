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
    int n,m,x,i,j,T;
    double c,error,a[200001],real[200001],approx[200001];
    cin>>n>>T>>c;
    approx[0]=real[0]=0;
    for( i=1; i<=n; i++ ){
        cin>>a[i];
        real[i]+=real[i-1]+a[i];
        approx[i]=(approx[i-1]+a[i]/T)/c;
    }
    cin>>m;
    for( i=1; i<=m; i++ ){
        cin>>x;
        error=(abs(approx[x]-(real[x]-real[x-T])/T))/((real[x]-real[x-T])/T);
        printf( "%.6f %.6f %.6f\n", (real[x]-real[x-T])/T, approx[x], error );
    }
}