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

const int N = 505;

using namespace std;

int n, i, j, h, cnt;
string s, ans = "1";

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> s;
        if( s.size() == 1 && s[0] == '0' ){
            cout << 0 << endl;
            return 0;
        }
        bool b1 = false;
        int g = 0;
        for( j = 0; j < s.size(); j++ ){
            if( s[j] > '1' )b1 = true;
            if( s[j] == '1' )g++;
        }
        if( b1 || g > 1 )ans = s;
        else cnt += s.size() - 1;
    }
    cout << ans;
    for( i = 0; i < cnt; i++ )cout << 0;
}