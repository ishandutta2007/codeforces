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

lli x, ans, i, mod = 1e5;
string s;

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i += 2 )x = x * 10 + (s[i] - '0');
    for( i = s.size() - 2; i > 0; i -= 2 )x = x * 10 + (s[i] - '0');
    for( ans = x, i = 1; i < 5; i++ )ans = (ans * x) % mod;
    x = ans;
    lli g = 0;
    while( x ){
        x /= 10;
        g++;
    }
    cout << ans;
    for( i = 1; i < 5 - g; i++ )cout << 0;
}