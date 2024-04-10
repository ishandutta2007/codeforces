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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int cnt, i, last, a;
pair < int, int > p[500001];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ )cin >> p[i].se >> p[i].fi;
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        if( p[i].se > last ){
            cnt++;
            last = p[i].fi;
        }
    }
    cout << cnt << endl;
}