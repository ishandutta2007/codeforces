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
#define fin freopen( "cordon.in", "r", stdin );
#define fout freopen( "cordon.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, t, i, j, h, cnt1, cnt2, ans1, ans2;
string s1, s2, ans;
vector < int > v1, v2;

char g( char x, char y )
{
    char c = 'a';
    while( c == x || c == y )c++;
    return c;
}

int main()
{
    cin >> a >> t;
    cin >> s1 >> s2;
    for( i = 0; i < a; i++ ){
        ans += 'a';
        if( s1[i] != s2[i] )v1.pb(i);
        else{
            v2.pb(i);
            ans[i] = s1[i];
        }
    }
    for( i = 0; i < v1.size(); i++ ){
        if( i % 2 ){
            ans[v1[i]] = s1[v1[i]];
            cnt2++;
        }
        else{
            ans[v1[i]] = s2[v1[i]];
            cnt1++;
        }
    }
    if( v1.size() % 2 ){
        ans[v1.back()] = g(s1[v1.back()], s2[v1.back()]);
        v1.p_b();
        cnt2++;
    }
    t -= cnt1;
    while( t > 0 && v1.size() ){
        int x = v1[v1.size() - 1], y = v1[v1.size() - 2];
        v1.p_b();
        v1.p_b();
        t --;
        ans[x] = g(s1[x], s2[x]);
        ans[y] = g(s1[y], s2[y]);
    }
    if( t < 0 ){
        cout << -1;
        return 0;
    }
    if( t == 0 ){
        cout << ans;
        return 0;
    }
    for( i = 0; i < v2.size(); i++ ){
        if( t ){
            ans[v2[i]] = g(s1[v2[i]], s1[v2[i]]);
            t--;
        }
    }
    if( t )cout << -1;
    else cout << ans;
}