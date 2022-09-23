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

int n, d[500005], i, j, h, x, y;
vector < int > v;

int main()
{
    cin >> n;
    for( i = 1; i <= 500000; i++ ){
        h = i;
        for( j = 2; j * j <= h; j++ ){
            while( h % j == 0 ){
                h /= j;
                if( j == 2 )x++;
                if( j == 5 )y++;
            }
        }
        if( h == 2 )x++;
        if( h == 5 )y++;
        d[i] = min(x, y);
    }
    for( i = 1; i <= 500000; i++ ){
        if( d[i] == n )v.pb(i);
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}