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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, x, y, i, j, h, b, dx[100001], dy[100001];
map < int, set < pair < int, int > > > s; 
pair < int, int > ans[100001];

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> x >> y;
        s[y - x].insert(mp(x, y));
    }
    for( i = 1; i <= a; i++ ){
        cin >> b;
        if( s[b].empty() ){
            cout << "NO" << endl;
            return 0;
        }
        ans[i] = *s[b].begin();
        s[b].erase(s[b].begin());
    }
    for( i = 1; i <= a; i++ ){
        if( ans[i].fi != dx[ans[i].se] || ans[i].se != dy[ans[i].fi] ){
            cout << "NO" << endl;
            return 0;
        }
        dx[ans[i].se]++;
        dy[ans[i].fi]++;
    }
    cout << "YES" << endl;
    for( i = 1; i <= a; i++ )cout << ans[i].fi << " " << ans[i].se << endl;
}