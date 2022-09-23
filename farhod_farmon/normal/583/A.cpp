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
int a, x, y, i;
bool used[100][3];

int main()
{
    cin >> a;
    for( i = 1; i <= a * a; i++ ){
        cin >> x >> y;
        if( used[x][1] || used[y][2] )continue;
        used[x][1] = used[y][2] = true;
        cout << i << " ";
    }
}