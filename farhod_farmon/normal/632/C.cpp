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

int n;
string s[50005];

bool M( string x, string y )
{
    string xx = x + y, yy = y + x;
    return xx < yy;
}

int main()
{
    int i;
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> s[i];
    sort( s + 1, s + n + 1, M );
    for( i = 1; i <= n; i++ )cout << s[i];
}