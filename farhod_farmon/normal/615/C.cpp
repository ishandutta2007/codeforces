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
#define fin freopen( "blocks.in", "r", stdin );
#define fout freopen( "blocks.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int d[2222], heh;
pair < int, pair < int, int > > p[2222], k, k1;

pair < int, pair < int, int > > Z( string s )
{
    int z[4444], i, j, l, r, cnt = 0;
    for( i = 0; i < s.size(); i++ )z[i] = 0;
    for( i = 1, l = r = 0; i < s.size(); i++ ){
        if( i <= r )z[i] = min(r - i + 1, z[i - l]);
        while( i + z[i] < s.size() && s[z[i]] == s[z[i] + i] )z[i]++;
        if( z[i] + i - 1 > r ){
            l = i;
            r = z[i] + i - 1;
        }
    }
    int ll = s.size() - heh;
    for( i = ll; i < s.size(); i++ ){
        if( z[i] > cnt ){
            cnt = z[i];
            l = i - ll + 1;
            r = i - ll + z[i];
        }
    }
    return mp(cnt, mp(l, r));
}

int main()
{
    string s, t, s1;
    int i, j, l, r, g, f;
    cin >> s >> t;
    heh = s.size();
    s1 = s;
    for( i = 0; i < s.size() / 2; i++ )swap(s1[i], s1[s1.size() - i - 1]);
    for( i = 0; i < t.size(); i++ )d[i] = 1e9;
    for( i = 0; i < t.size(); i++ ){
        if( i != 0 && d[i - 1] == 1e9 )continue;
        string h = "";
        for( j = i; j < t.size(); j++ )h += t[j];
        k = Z(h + "#" + s);
        k1 = Z(h + "#" + s1);
        if( i == 0 )f = 0;
        else f = d[i - 1];
        k.fi--;
        k1.fi--;
        if( k.fi >= 0 && f + 1 < d[i + k.fi] ){
            d[i + k.fi] = f + 1;
            p[i + k.fi] = mp(1, k.se);
        }
        if( k1.fi >= 0 && f + 1 < d[i + k1.fi] ){
            d[i + k1.fi] = f + 1;
            p[i + k1.fi] = mp(-1, k1.se);
        }
    }
    if( d[t.size() - 1] == 1e9 ){
        cout << -1 << endl;
        return 0;
    }
    vector < pair < int, int > > ans;
    int lem = t.size() - 1;
    cout << d[lem] << endl;
    while( lem >= 0 ){
        if( p[lem].fi == -1 )p[lem].se = mp(heh - p[lem].se.fi + 1, heh - p[lem].se.se + 1);
        ans.pb(p[lem].se);
        lem -= (abs(p[lem].se.se - p[lem].se.fi) + 1);
    }
    for( i = ans.size() - 1; i >= 0; i-- )cout << ans[i].fi << " " << ans[i].se << endl;
}