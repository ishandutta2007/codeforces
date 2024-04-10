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
set < pair < int, int > > s[30];
set < pair < int, int > > :: iterator t1, t2, it;
int n, q, i, j, h, k, l, r, m, g, g1, g2, inf = 100011;
char c[200001], ans[200001];

int main()
{
    sc( "%d%d", &n, &q );
    sc( "%s", &c );
    for( i = 0; i < n; i++ ){
        j = i;
        while( j + 1 < n && c[i] == c[j + 1] )j++;
        s[c[i] - 'a'].insert({i, j});
        i = j;
    }
    for( j = 0; j < 26; j++ ){
        s[j].insert({inf, inf});
        s[j].insert({-inf, -inf});
    }
    for( i = 1; i <= q; i++ ){
        sc( "%d%d%d", &l, &r, &k );
        l--;
        r--;
        if( k )g = l;
        else g = r;
        for( j = 0; j < 26; j++ ){
            bool b1 = true;
            g1 = 0;
            while( b1 ){
                it = s[j].lower_bound({l, -1});
                if( it->fi > r )it--;
                if( it->se < l || it->fi > r )break;
                if( it->fi >= l && it->se <= r ){
                    g1 += (it->se - it->fi) + 1;
                    s[j].erase(it);
                }
                else if( it->fi < l && it->se > r ){
                    s[j].insert({it->fi, l - 1});
                    s[j].insert({r + 1, it->se});
                    g1 += (r - l) + 1;
                    s[j].erase(it);
                }
                else if( it->fi >= l && it->fi <= r ){
                    s[j].insert({r + 1, it->se});
                    g1 += (r - it->fi) + 1;
                    s[j].erase(it);
                }
                else if( it->se >= l && it->se <= r ){
                    s[j].insert({it->fi, l - 1});
                    g1 += (it->se - l) + 1;
                    s[j].erase(it);
                }
                else b1 = false;
            }
            if( g1 ){
                if( k ){
                    s[j].insert({g, g + g1 - 1});
                    g += g1;
                }
                else{
                    s[j].insert({g - g1 + 1, g});
                    g -= g1;
                }
            }
        }
    }
    for( i = 0; i < 26; i++ ){
        it = s[i].begin();
        it++;
        while( it != s[i].end() ){
            for( j = it->fi; j <= it->se; j++ )ans[j] = char(i + 'a');
            it++;
        }
    }
    for( i = 0; i < n; i++ )pr( "%c", ans[i] );
}