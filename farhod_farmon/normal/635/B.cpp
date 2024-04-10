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

int n, in[200002], x, y, i, j, h, a, b[200002], l = -1, r;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a;
        in[a] = i;
    }
    for( i = 1; i <= n; i++ ){
        cin >> b[i];
        if( !b[i] )continue;
        x = 0;
        if( i != in[b[i]] ){
            x += in[0] - in[b[i]];
            if( x < 0 )x += n;
            if( i > in[b[i]] )x += (i - in[b[i]] - 1) * (n - 1);
            else x += (n - in[b[i]] - 1) * (n - 1) + i * (n - 1);
        }
        if( l == -1 )l = x, r = x + n - 2;
        else l = max(l, x), r = min(r, x + n - 2);
    }
    if( l <= r ){
        cout << "YES" << endl;
        return 0;
    }
    l = -1;
    for( i = 1; i <= n; i++ ){
        x = 0;
        if( !b[i] )continue;
        if( i != in[b[i]] ){
            x += in[b[i]] - in[0];
            if( x < 0 )x += n;
            if( i < in[b[i]] )x += (in[b[i]] - i - 1) * (n - 1);
            else x += (in[b[i]] - 1) * (n - 1) + (n - i) * (n - 1);
        }
        if( l == -1 )l = x, r = x + n - 2;
        else l = max(l, x), r = min(r, x + n - 2);
    }
    if( l <= r ){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}