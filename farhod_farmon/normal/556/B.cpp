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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b[1001], i;
string ans = "Yes";

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
        if( i % 2 )b[i] = (i + a - b[i] - 1) % a;
        else b[i] = (b[i] + a - i + 1) % a;
        if( i > 1 && b[i] != b[i - 1] )ans = "No";
    }
    cout << ans;
}