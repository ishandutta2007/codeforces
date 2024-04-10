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
    bool b1;
    int a,b,i,j,cnt=0;
    char c[11][11];
    cin>>a>>b;
    REP(i,a) REP(j,b) cin>>c[i][j];
    REP(i,a){ b1=true;
        REP(j,b) if( c[i][j]=='S' ) b1=false;
        if(b1) REP(j,b) c[i][j]='x';
    }
    REP(i,b){ b1=true;
        REP(j,a) if( c[j][i]=='S' ) b1=false;
        if(b1) REP(j,a) c[j][i]='x';
    }
    REP(i,a) REP(j,b) if( c[i][j]=='x' )cnt++;
    cout<<cnt;
    return 0;
}