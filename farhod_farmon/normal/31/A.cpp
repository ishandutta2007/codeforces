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
    int a, b[1001], i, j, k;
    cin >> a;
    for( i = 1; i <= a; i ++ )cin >> b[i];
    for( i = 1; i <= a; i ++ )
    {
        for( j = 1; j <= a; j ++ )
        {
            for( k = 1; k <= a; k ++ )
            {
                if( i != j && i != k && j != k && b[i] + b[j] == b[k] )
                {
                    cout << k << " " << j << " " << i;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}