#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, a, ans[200002], k[200002];
vector < pair < pair < int, int >, int > > v;

bool f( int x )
{
    set < pair < int, int > > s;
    set < pair < int, int > > :: iterator it;
    int i, cnt = 0;
    for( i = 0; i < v.size(); i++ ){
        int l = v[i].fi.fi;
        int r = v[i].fi.se;
        int h = v[i].se;
        if( r == -1 ){
            if( s.find(mp(l, h)) != s.end() ){
                s.erase(mp(l, h));
                cnt++;
                ans[cnt] = h;
            }
        }
        else{
            if( s.size() != x )
                s.insert(mp(r, h));
            else{
                it = (--s.end());
                if( r < it->fi ){
                    s.erase(it);
                    s.insert(mp(r, h));
                }
            }
        }
    }
    return cnt >= a;
}

bool cmp( int x, int y )
{
    return k[x] < k[y];
}

int main()
{
    int i, j, h, d;
    sc( "%d%d", &n, &a );
    for( i = 1; i <= n; i++ ){
        sc( "%d%d", &k[i], &d );
        v.pb(mp(mp(k[i], k[i] + d), i));
        v.pb(mp(mp(k[i] + d, -1), i));
    }
    sort( v.begin(), v.end() );
    int l = 1;
    int r = n;
    while( l < r ){
        int m = (l + r) / 2;
        if( !f(m) )l = m + 1;
        else r = m;
    }
    f(l);
    pr( "%d\n", l );
    for( i = 1; i <= a; i++ )pr( "%d ", ans[i] );
}