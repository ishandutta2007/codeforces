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
string s;
vector < char > v;
int i, j;

int main()
{
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        v.pb(s[i]);
        if( v.size() > 1 && v[v.size() - 1] == v[v.size() - 2] ){
            v.p_b();
            v.p_b();
        }
    }
    for( i = 0; i < v.size(); i++ )cout << v[i];
}