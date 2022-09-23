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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
string s[10];
int a, i, j, h, g;

int main()
{
    cin >> a;
    s[1] = "+------------------------+";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[3] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[4] = "|#.......................|";
    s[5] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[6] = "+------------------------+";
    for( i = 2; i <= min(a, 4) + 1; i++ )s[i][1] = 'O';
    a -= min(4, a);
    g = a / 3 + 1;
    for( i = 2; i <= g + (a % 3 != 0) ? 1 : 0; i++ )s[2][i * 2 - 1] = 'O';
    for( i = 2; i <= g + (a % 3 == 2) ? 1 : 0; i++ )s[3][i * 2 - 1] = 'O';
    for( i = 2; i <= g; i++ )s[5][i * 2 - 1] = 'O';
    cout << s[1] << endl;
    cout << s[2] << endl;
    cout << s[3] << endl;
    cout << s[4] << endl;
    cout << s[5] << endl;
    cout << s[6] << endl;
}