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

int n, m, q, p[2001];
vector < pair < pair < int, int >, pair < int, int > > > edges;

int find(int x)
{
    if(x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{
    //fin
    //fout
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        edges.pb({{l, i}, {x, y}});
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= q; i++){
        int l, r, ans = -1;
        cin >> l >> r;
        for(int j = 1; j <= n + n; j++)
            p[j] = j;
        for(int j = m - 1; j >= 0; j--){
            int h = edges[j].fi.se;
            int k = edges[j].fi.fi;
            int x = edges[j].se.fi;
            int y = edges[j].se.se;
            if(h < l || h > r)
                continue;
            int px = find(x);
            int py = find(y);
            if(px == py){
                ans = k;
                break;
            }
            p[find(x + n)] = py;
            p[find(y + n)] = px;
        }
        cout << ans << endl;
    }
}