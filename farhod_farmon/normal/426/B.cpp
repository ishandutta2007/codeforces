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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
int main()
{
    int a, b, i, j, h, x1, y1, x2, y2, c[101][101];
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cin >> c[i][j];
        }
    }
    j = a;
    while( 1 < j && j % 2 == 0 ){
        y1 = (1 + j) / 2;
        x1 = 1;
        x2 = (1 + j) / 2 + 1;
        y2 = j;
        bool b1 = true;
        for( ; x1 <= y1 && y2 >= x2; x1++, y2-- ){
            for( h = 1; h <= b; h++ ){
                if( c[x1][h] != c[y2][h] )b1 = false;
            }
        }
        if( b1 )j = x2 - 1;
        else break;
    }
    cout << j;
}