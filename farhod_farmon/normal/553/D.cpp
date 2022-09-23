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

const int N = 100001;

using namespace std;

int n, m, k, cnt, x, y, i, z;
vector < int > v[N], g;
bool used[N], ans[N];
double S, d[N], d1[N];
set < pair < double, int > > s;

int main()
{
    cin >> n >> m >> k;
    for( i = 1; i <= k; i++ ){
        cin >> x;
        used[x] = true;
    }
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        d1[x]++;
        d1[y]++;
        if( used[x] || used[y] )
            continue;
        v[x].pb(y);
        v[y].pb(x);
        d[x]++;
        d[y]++;
    }
    for( i = 1; i <= n; i++ ){
        if( !used[i] ){
            s.insert(mp(d[i] / d1[i], i));
            ans[i] = true;
        }
    }
    S = s.begin()->fi;
    while( !s.empty() ){
        x = s.begin()->se;
        s.erase(s.begin());
        used[x] = true;
        g.pb(x);
        for( i = 0; i < v[x].size(); i++ ){
            y = v[x][i];
            if( used[y] )
                continue;
            s.erase(mp(d[y] / d1[y], y));
            d[y]--;
            s.insert(mp(d[y] / d1[y], y));
        }
        if( s.begin()->fi > S ){
            S = s.begin()->fi;
            for( i = 0; i < g.size(); i++ )
                ans[g[i]] = false;
            g.clear();
        }
    }
    int cnt = 0;
    for( i = 1; i <= n; i++ )
        cnt += ans[i];
    cout << cnt << endl;
    for( i = 1; i <= n; i++ )
        if( ans[i] )
            cout << i << " ";
}