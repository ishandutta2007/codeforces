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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int cnt, i, r[5005];
string s;

int main()
{
    cin >> s;
    for( i = s.size() - 1; i >= 3; i-- ){
        r[i] = r[i + 1];
        if( s[i] == 'r' && s[i - 1] == 'a' && s[i - 2] == 'e' && s[i - 3] == 'b' )r[i] = i;
    }
    for( i = 0; i + 3 < s.size(); i++ ){
        if( !r[i + 3] )break;
        cnt += s.size() - r[i + 3];
    }
    cout << cnt << endl;
}