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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, ans;
vector < int > v;
bool used[111];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            cin >> b;
            if( b == 1 || b == 1 )used[i] = true;
            if( b == 2 || b == 3 )used[j] = true;
        }
    }
    for( i = 1; i <= a; i++ ){
        if( !used[i] )v.pb(i);
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}