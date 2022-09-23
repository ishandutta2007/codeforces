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
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
vector < int > v[3001];
int a, b, ans, d[3001], r;
bool used[3001][3001];

int main()
{
    int x, y, i, j, h;
    sc( "%d%d", &a, &b );
    for( i = 1; i <= b; i++ ){
        sc( "%d%d", &x, &y );
        used[x][y] = true;
        v[x].pb(y);
    }
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            if( i == j )continue;
            r = 0;
            for( h = 0; h < v[i].size(); h++ ){
                if( v[i][h] != i && v[i][h] != j && used[v[i][h]][j] )r++;
            }
            ans += r * (r - 1) / 2;
        }
    }
    pr( "%d", ans );
}