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
int a, b[211], c[211], d[211][211], ans = 9999999999;
bool used[201];

bool sanj( int x )
{
    for( int i = 1; i <= b[x]; i++ ){
        if( !used[d[x][i]] )return false;
    }
    return true;
}

int main()
{
    sc("%d", &a);
    for( int i = 1; i <= a; i++ )sc("%d", &c[i]);
    for( int i = 1; i <= a; i++ ){
        sc("%d", &b[i]);
        for( int j = 1; j <= b[i]; j++ )sc("%d", &d[i][j]);
    }
    for( int i = 1; i <= 3; i++ ){
        for( int j = 1; j <= a; j++ )used[j] = false;
        int j = 1;
        for( j; ; j++ ){
            bool b1 = true;
            for( int h = 1; h <= a; h++ ){
                if( !used[h] )b1 = false;
            }
            if( b1 )break;
            for( int h1 = 1; h1 <= a; h1++ ){
                for( int h = 1; h <= a; h++ ){
                    if( c[h] == (i + j) % 3 + 1 && sanj(h) && !used[h] )used[h] = true;
                }
            }
        }
        ans = min(ans, j - 1);
    }
    pr("%d", ans + a - 1);
}