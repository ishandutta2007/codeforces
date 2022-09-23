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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
string s, t;
int i, j, h, cnt, x = -1, l, r, m;
vector < int > v[200];

int main()
{
    cin >> s >> t;
    for( i = 0; i < s.size(); i++ )v[s[i]].pb(i);
    for( i = 0; i < t.size(); i++ ){
        l = 0;
        r = v[t[i]].size() - 1;
        if( r < 0 ){
            cout << -1;
            return 0;
        }
        while(l < r){
            m = (l + r) / 2;
            if( v[t[i]][m] <= x )l = m + 1;
            else r = m;
        }
        if( v[t[i]][l] > x )x = v[t[i]][l];
        else x = v[t[i]][0], cnt++;
    }
    cout << cnt + 1;
}