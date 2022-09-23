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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

lli n, a, b, c, ans, cnt;

int main()
{
    cin >> n >> a >> b >> c;
    ans = n / a;
    if( n >= b ){
        cnt = (n - b) / (b - c) + 1;
        cnt += (n - cnt * b + cnt * c) / a;
    }
    cout << max(ans, cnt) << endl;
}