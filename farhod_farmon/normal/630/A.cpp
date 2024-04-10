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

lli bp( lli x )
{
    if( x == 0 )return 1;
    if( x % 2 )return (5 * bp(x - 1)) % 100;
    lli g = bp(x / 2);
    return (g * g) % 100;
}

int main()
{
    lli n;
    cin >> n;
    cout << bp(n) << endl;
}