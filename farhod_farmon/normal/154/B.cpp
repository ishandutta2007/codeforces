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
using namespace std;
vector < int > v[100001];
bool used[100001], g[100001];
int i, j, a, b, x, y, d[100001], d1[100001][10];
char c;

int main()
{
    for( i = 2; i <= 100000; i++ ){
        v[i].pb(i);
        if( !used[i] ){
            for( j = i + i; j <= 100000; j += i ){
                v[j].pb(i);
                used[j] = 1;
            }
        }
    }
    cin >> a >> b;
    for( i = 1; i <= b; i++ ){
        cin >> c >> x;
        if( c == '+' ){
            if( g[x] ) pr( "Already on\n" );
            else{
                int gg = -1;
                for( j = 0; j < v[x].size(); j++ ){
                    d[v[x][j]]++;
                    d1[v[x][j]][d[v[x][j]]] = x;
                    if( d[v[x][j]] > 1 )gg = j;
                }
                if( gg >= 0 ){
                    pr( "Conflict with %d\n", d1[v[x][gg]][d[v[x][gg]] - 1] );
                    for( j = 0; j < v[x].size(); j++ )d[v[x][j]]--;
                }
                else{
                    g[x] = 1;
                    pr( "Success\n" );
                }
            }
        }
        else{
            if( !g[x] )pr( "Already off\n" );
            else{
                for( j = 0; j < v[x].size(); j++ )d[v[x][j]]--;
                g[x] = 0;
                pr( "Success\n" );
            }
        }
    }
}