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

long double a, b, c, d, s1, s2;

int main()
{
    cin >> a >> b >> c;
    d = b * b - 4. * a * c;
    s1 = (-b + sqrt(d)) / (2. * a);
    s2 = (-b - sqrt(d)) / (2. * a);
    pr( "%.6lf\n%.6lf", (double)max(s1, s2), (double)min(s1, s2) );
}