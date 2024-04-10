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
#define fin freopen( "next.in", "r", stdin );
#define fout freopen( "next.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, d[200][200], ans;
string s;
char x, y;
map < vector < char >, int > m;
vector < char > v, v1, v2;
bool used[200];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> s;
        v.clear();
        for( j = 'a'; j <= 'z'; j++ )used[j] = false;
        for( j = 0; j < s.size(); j++ ){
            if( !used[s[j]] ){
                v.pb(s[j]);
                used[s[j]] = true;
            }
        }
        sort( v.begin(), v.end() );
        m[v] += s.size();
    }
    for( i = 'a'; i <= 'z'; i++ ){
        for( j = i; j <= 'z'; j++ ){
            v.clear();
            v1.clear();
            v2.clear();
            if( i == j ){
                v.pb(i);
            }
            else{
                v.pb(i);
                v1.pb(j);
                v2.pb(i);
                v2.pb(j);
            }
            ans = max(ans, m[v] + m[v1] + m[v2]);
        }
    }
    cout << ans << endl;
}