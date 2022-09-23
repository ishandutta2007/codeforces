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

lli n, i, d[30], d1[30];

int main()
{
    d[1] = 3;
    d[2] = 9;
    d1[1] = 3;
    for( i = 3; i <= 29; i++ )d[i] = d[i - 1] * 4;
    for( i = 2; i <= 29; i++ )d1[i] = d1[i - 1] * 4;
    cin >> n;
    cout << 4 * (2 * d1[n - 2] + (n - 3) * d[n - 2]);
}