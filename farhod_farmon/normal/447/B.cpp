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
int cnt, i, k, d[200], j;
string s;

int main()
{
    cin >> s;
    cin >> k;
    for( char c = 'a'; c <= 'z'; c++ ){
        cin >> d[c];
        if( d[c] > j )j = d[c];
    }
    for( i = 0; i < s.size(); i++ )cnt += d[s[i]] * (i + 1);
    for( i = s.size(); i < s.size() + k; i++ )cnt += j * (i + 1);
    cout << cnt << endl;
}