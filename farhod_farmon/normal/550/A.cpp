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
#define fin freopen( "bet.in", "r", stdin );
#define fout freopen( "bet.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s;
    int i;
    vector < int > v, v1;
    cin >> s;
    for( i = 0; i < s.size() - 1; i++ ){
        if( s[i] == 'B' && s[i + 1] == 'A' )v.pb(i);
        if( s[i] == 'A' && s[i + 1] == 'B' )v1.pb(i);
    }
    if( !v.size() || !v1.size() )cout << "NO";
    else if( v1.back() - v[0] > 1 || v.back() - v1[0] > 1 )cout << "YES";
    else cout << "NO";
}