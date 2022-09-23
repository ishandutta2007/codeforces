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
#include <iomanip>

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

using namespace std;

vector < int > v;
int l, r, i, j, n;
pair < int, int > p[1001];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> p[i].fi >> p[i].se;
        if( p[i].se < p[i].fi )swap(p[i].fi, p[i].se);
    }
    sort( p + 1, p + n + 1 );
    for( i = 1; i <= n; i++ ){
        r =  p[i].se;
        while( i + 1 <= n && p[i + 1].fi <= r )r = min(r, p[++i].se);
        v.pb(r);
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}