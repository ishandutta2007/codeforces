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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
vector < int > v1, v2, v3;
int a, i, j, x;
pair < int, int > p[2001];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        v1.pb(i);
        v2.pb(i);
        v3.pb(i);
    }
    for( i = 0; i < a - 1; i++ ){
        if( p[v2[i]].fi == p[v2[i + 1]].fi ){
            swap( v2[i], v2[i + 1] );
            swap( v3[i], v3[i + 1] );
            break;
        }
    }
    if( i == a - 1 ){
        cout << "NO\n";
        return 0;
    }
    for( i = i + 1; i < a - 1; i++ ){
        if( p[v3[i]].fi == p[v3[i + 1]].fi ){
            swap( v3[i], v3[i + 1] );
            break;
        }
    }
    if( i == a - 1 ){
        cout << "NO\n";
        return 0;
    }
    else cout << "YES\n";
    for( i = 0; i < a; i++ )cout << p[v1[i]].se << " ";
    cout << "\n";
    for( i = 0; i < a; i++ )cout << p[v2[i]].se << " ";
    cout << "\n";
    for( i = 0; i < a; i++ )cout << p[v3[i]].se << " ";
}