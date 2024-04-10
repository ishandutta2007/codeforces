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

int n, i, j, h, x, y, cnt = 1;
pair < int, int > p[1000];
char c;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> c >> x >> y;
        for( j = x; j <= y; j++ ){
            if( c == 'M' )p[j].fi++;
            else p[j].se++;
        }
    }
    for( i = 2; i <= 366; i++ ){
        if( min(p[i].fi, p[i].se) * 2 > min(p[cnt].fi, p[cnt].se) * 2 )cnt = i;
    }
    cout << min(p[cnt].fi, p[cnt].se) * 2;
}