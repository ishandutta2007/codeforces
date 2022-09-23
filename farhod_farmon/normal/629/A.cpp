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

int i, j, n, a[101], b[101], cnt;
char c;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            cin >> c;
            if( c == 'C' ){
                a[i]++;
                b[j]++;
            }
        }
    }
    for( i = 1; i <= n; i++ )cnt += a[i] * (a[i] - 1) / 2 + b[i] * (b[i] - 1) / 2;
    cout << cnt << endl;
}