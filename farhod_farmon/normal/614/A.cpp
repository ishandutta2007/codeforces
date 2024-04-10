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

const int N = 505;

using namespace std;

lli l, r, k, g = 1, cnt;

int main()
{
    cin >> l >> r >> k;
    while( true ){
        if( l <= g ){
            cout << g << " ";
            cnt++;
        }
        if( g <= r / k )g *= k;
        else break;
    }
    if( !cnt )cout << -1 << endl;
}