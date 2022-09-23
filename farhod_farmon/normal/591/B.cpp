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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, d[200];
string s;
char x[200001], y[200001];

int main()
{
    cin >> a >> b;
    cin >> s;
    for( i = 1; i <= b; i++ )cin >> x[i] >> y[i];
    for( i = 0; i < 26; i++ )d[i] = i;
    for( i = b; i >= 1; i-- )swap(d[x[i] - 'a'], d[y[i] - 'a']);
    for( i = 0; i < a; i++ )cout << char(d[s[i] - 'a'] + 'a');
}