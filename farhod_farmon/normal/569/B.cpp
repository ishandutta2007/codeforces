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
int a, g, i, b[100011], d[100011];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
        d[b[i]]++;
    }
    for( i = g = 1; i <= a; i++ ){
        if( d[b[i]] == 1 && b[i] <= a ){
            cout << b[i] << " ";
            continue;
        }
        while( d[g] )g++;
        d[b[i]]--;
        cout << g << " ";
        g++;
    }
}