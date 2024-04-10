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
int main()
{
    string s[100001];
    int cnt = 0, i = 1, j = 0, g, si = 0, h, m = 0;
    while( getline( cin, s[i] ) ){
        g = s[i].size();
        si = max( si, g );
        i ++;
    }
    g = i;
    for( i = 1; i <= si+2; i ++ )pr("*");
    pr("\n");
    for( i = 1; i < g; i ++ ){
        pr("*");
        h = ( si - s[i].size() + m ) / 2;
        for( j = 1; j <= h; j ++ )pr(" ");
        cout << s[i];
        j += s[i].size();
        for( ; j <= si; j ++ )pr(" ");
        pr("*\n");
        if( (si%2 == 1 && s[i].size() % 2 == 0) || (si % 2 == 0 && s[i].size() % 2 == 1) )m = ( m + 1 ) % 2;
    }
    for( i = 1; i <= si+2; i ++ )pr("*");
    return 0;
}