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

int n, m, k, i, j, h, x, d[10001];

int main()
{
    fin
    fout
    cin >> n >> k;
    d[0] = 1;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        x *= n - i + 1;
        for( j = k; j >= x; j-- ){
            if( d[j - x] )d[j] = max(d[j], d[j - x] + 1);
        }
    }
    x = 0;
    for( i = 1; i <= k; i++ ){
        if( d[i] > d[x] )x = i;
    }
    cout << d[x] - 1 << endl;
}