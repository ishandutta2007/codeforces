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
    lli x1, y1, x2, y2, cnt = 0, a, b, c, d;
    cin >> x1 >> y1 >> x2 >> y2;
    a = (x2 - x1) / 2;
    b = (y2 - y1) / 2;
    cout << a * b + (a + 1) * (b + 1);
}