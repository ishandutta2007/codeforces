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

lli n, a[100001], i, x, ans;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    for( i = 1; i <= n; i++ ){
        x = 0;
        while( a[i] == a[i + x] && i + x <= n )x++;
        ans += x * (x + 1) / 2;
        i += x - 1;
    }
    cout << ans << endl;
}