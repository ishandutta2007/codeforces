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
string s, t, x = "0";
int i, j, h, ans;

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        t = s[i];
        while( i + 1 < s.size() && s[i + 1] == '0' )t += '0', i++;
        if( x.size() > t.size() || x.size() == t.size() && x >= t )ans++;
        else ans = 1;
        if( x == "0" )x = t;
        else x += t;
    }
    cout << ans << endl;
}