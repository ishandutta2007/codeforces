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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int i, a, b, h, j, l, r, k;
string s, t;

int main()
{
    cin >> s;
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> l >> r >> k;
        k %= r - l + 1;
        t = "";
        for( j = r - k; j < r; j++ )t += s[j];
        for( j = l - 1; j < r - k; j++ )t += s[j];
        for( j = 0; j < t.size(); j++ )s[j + l - 1] = t[j];
    }
    cout << s << endl;
}