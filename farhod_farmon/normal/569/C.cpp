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
int nmax = 10000000, p, q, d[10000001], d1[10000001], ans;
bool used[10000001];

bool pa( int x )
{
    int g = 0, c[10];
    while( x > 0 ){
        g++;
        c[g] = x % 10;
        x /= 10;
    }
    for( int i = 1; i <= g / 2; i++ ){
        if( c[i] != c[g - i + 1] )return false;
    }
    return true;
}

int main()
{
    lli i, j, h;
    cin >> p >> q;
    for( i = 2; i <= nmax; i++ ){
        d[i] = d[i - 1];
        if( used[i] )continue;
        for( j = i * i; j <= nmax; j += i )used[j] = true;
        d[i]++;
    }
    for( i = 1; i <= nmax; i++ ){
        d1[i] = d1[i - 1] + pa(i);
            if( (d1[i] * p) / q >= d[i] )ans = i;
    }
    cout << ans;
}