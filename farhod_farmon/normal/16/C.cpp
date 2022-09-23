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

int main()
{
    lli a, b, x, y, g;
    cin >> a >> b >> x >> y;
    g = __gcd(x, y);
    x /= g; y /= g;
    g = min(a / x, b / y);
    cout << x * g << " " << y * g << endl;
}