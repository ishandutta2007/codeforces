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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int x, y, a, b, i, j, h, cnt;
string s;
bool used[555][555];

int main()
{
    cin >> a >> b >> x >> y;
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        if( !used[x][y] )cnt++;
        if( !used[x][y] )cout << "1 ";
        else cout << "0 ";
        used[x][y] = true;
        if( s[i] == 'U' )x = max(1, x - 1);
        if( s[i] == 'D' )x = min(a, x + 1);
        if( s[i] == 'L' )y = max(1, y - 1);
        if( s[i] == 'R' )y = min(b, y + 1);
    }
    cout << max(0, a * b - cnt) << endl;
}