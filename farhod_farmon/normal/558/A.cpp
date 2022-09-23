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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, g, d[300001],i, x, cnt1, cnt2;
bool used[10011], b1;
pair < int, int > p[1001];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> p[i].fi >> p[i].se;
    }
    sort( p + 1, p + a + 1 );
    for( i = 1; i <= a; i++ ){
        if( p[i].fi > 0 ){
            x = i;
            break;
        }
    }
    g = x - 1;
    b1 = true;
    if( g < 0 )g = a;
    while( g && g <= a ){
        cnt1 += p[g].se;
        if( b1 ){
            used[g] = true;
            while( used[g] )g++;
            b1 = false;
        }
        else{
            used[g] = true;
            while( used[g] )g--;
            b1 = true;
        }
    }
    for( i = 0; i <= a + 1; i++ )used[i] = false;
    g = x;
    b1 = false;
    while( g && g <= a ){
        cnt2 += p[g].se;
        if( b1 ){
            used[g] = true;
            while( used[g] )g++;
            b1 = false;
        }
        else{
            used[g] = true;
            while( used[g] )g--;
            b1 = true;
        }
    }
    cout << max(cnt1, cnt2);
}