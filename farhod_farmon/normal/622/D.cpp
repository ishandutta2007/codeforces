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

int n, d[1000001], i, j;

int main()
{
    cin >> n;
    for( i = 1, j = n; i < n; i += 2 )d[(i + 1) / 2] = d[j--] = i;
    for( i = 2, j = 2 * n - 1; i < n; i += 2 )d[n + i / 2] = d[j--] = i;
    for( i = 1; i <= 2 * n; i++ ){
        if( !d[i] )cout << n << " ";
        else cout << d[i] << " ";
    }
}