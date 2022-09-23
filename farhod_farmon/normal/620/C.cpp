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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

const int N = 300003;

using namespace std;

vector < int > v;
int n, d[N], i, j, h, l = 1, x;
map < int, int > m;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        if( m[x] >= l ){
            v.pb(l);
            l = i + 1;
        }
        m[x] = i;
    }
    if( !v.size() ){
        cout << -1 << endl;
        return 0;
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size() - 1; i++ )cout << v[i] << " " << v[i + 1] - 1 << endl;
    cout << v[i] << " " << n << endl;
}