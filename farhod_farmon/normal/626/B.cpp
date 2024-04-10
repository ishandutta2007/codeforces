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

bool used[202][202][202];
int n, d[4];
string s, ans;

void cr()
{
    int i, j, h;
    for( i = 0; i <= d[1]; i++ ){
        for( j = 0; j <= d[2]; j++ ){
            for( h = 0; h <= d[3]; h++ )used[i][j][h] = 0;
        }
    }
}

void rec( int x, int y, int z )
{
    if( x > d[1] + 1 || y > d[2] + 1 || z > d[3] + 1 || used[x][y][z] )return;
    used[x][y][z] = true;
    if( x ){
        rec(x + 1, y, z);
        rec(x - 1, y + 1, z + 1);
    }
    if( y ){
        rec(x, y + 1, z);
        rec(x + 1, y - 1, z + 1);
    }
    if( z ){
        rec(x, y, z + 1);
        rec(x + 1, y + 1, z - 1);
    }
}

int main()
{
    int i;
    cin >> n >> s;
    for( i = 0; i < n; i++ ){
        if( s[i] == 'B' )d[1]++;
        else if( s[i] == 'G' )d[2]++;
        else d[3]++;
    }
    cr(); rec(1, 0, 0);
    if( used[d[1]][d[2]][d[3]] )ans += 'B';
    cr(); rec(0, 1, 0);
    if( used[d[1]][d[2]][d[3]] )ans += 'G';
    cr(); rec(0, 0, 1);
    if( used[d[1]][d[2]][d[3]] )ans += 'R';
    cout << ans << endl;
}