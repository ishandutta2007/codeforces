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
int a, cnt, b[102], i, j, h;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ )cin >> b[i];
    for( i = 1; i <= a; i++ ){
        h = 0;
        for( j = i; j <= a; j++ ){
            if( !h && (j == 1 || j == a) )h++;
            if( b[j] )break;
            h++;
        }
        if( h > 1 )i = j - 1;
        else cnt++;
    }
    cout << cnt << endl;
}