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

long double m = 1.000000011;

long double bp( lli x )
{
    if( x == 0 )return 1;
    if( x % 2 )return m * bp(x - 1);
    long double g = bp(x / 2);
    return g * g;
}

int main()
{
    long double g;
    lli n;
    cin >> n >> g;
    cout << bp(g) * n << endl;
}