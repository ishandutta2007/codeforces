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

lli n, m, x, y, i;

int main()
{
    cin >> n >> m;
    x = n * 2;
    y = m * 3;
    for( i = 1; i * 6 <= min(x, y); i++ ){
        if( y < x )y += 3;
        else x += 2;
    }
    cout << max(x, y) << endl;
}