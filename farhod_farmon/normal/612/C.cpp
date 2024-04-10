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
#define fin freopen( "b.in", "r", stdin );
#define fout freopen( "b.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

string s;
vector < char > v;
char c[300];
int ans, i;

int main()
{
    c['}'] = '{';
    c[']'] = '[';
    c['>'] = '<';
    c[')'] = '(';
    cin >> s;
    for( i = 0; i < s.size(); i++ ){
        if( s[i] == '{' || s[i] == '[' || s[i] == '<' || s[i] == '(' )v.pb(s[i]);
        else{
            if( !v.size() ){
                cout << "Impossible" << endl;
                return 0;
            }
            if( c[s[i]] != v.back() )ans++;
            v.p_b();
        }
    }
    if( v.size() ){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ans << endl;
}