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
#define fin freopen( "dfs.in", "r", stdin );
#define fout freopen( "dfs.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
queue < int > v1, v2;
int a, k1, k2, x, i, j, h, cnt;
vector < queue < int > > v;

int main()
{
    cin >> a;
    cin >> k1;
    for( i = 1; i <= k1; i++ ){
        cin >> x;
        v1.push(x);
    }
    cin >> k2;
    for( i = 1; i <= k2; i++ ){
        cin >> x;
        v2.push(x);
    }
    while( !v1.empty() && !v2.empty() ){
        cnt++;
        if( v1.front() > v2.front() ){
            v1.push(v2.front());
            v1.push(v1.front());
            v1.pop();
            v2.pop();
        }
        else{
            v2.push(v1.front());
            v2.push(v2.front());
            v1.pop();
            v2.pop();
        }
        if( cnt > a * a + 10){
            cout << -1;
            return 0;
        }
        v.pb(v1);
    }
    cout << cnt << " " << (!v1.empty() ? 1 : 2);
}