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

int n, i, j, cnt;
string s;

void f( char c, int &x, int &y )
{
    if( c == 'U' )x--;
    if( c == 'D' )x++;
    if( c == 'R' )y++;
    if( c == 'L' )y--;
}

int main()
{

    int x, y;
    cin >> n >> s;
    for( i = 0; i < n; i++ ){
        x = y = 0;
        for( j = i; j < n; j++ ){
            f(s[j], x, y);
            if( x == 0 && y == 0 )cnt++;
        }
    }
    cout << cnt << endl;
}