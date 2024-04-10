#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int n, m, k;
long long ans[N + N];
bool us1[N + N], us2[N + N];
vector < pair < pair < int, int >, int > > v1[N + N], v2[N + N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    //cin >> n >> m >> k;
    sc("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        int x, y;
        //cin >> x >> y;
        sc("%d%d", &x, &y);
        v1[x + y].pb({{x, y}, i});
        v2[x - y + N].pb({{x, y}, i});
        ans[i] = 1e18;
    }
    long long t = 0,
        x = 0,
        y = 0,
        tx = 1,
        ty = 1;
    while(true){
        if(x == n && y == m || x == n && y == 0 || x == 0 && y == m)
            break;
        if(tx == 1 && ty == 1){
            int g = min(m - y, n - x);
            for(auto p: v2[x - y + N]){
                int nx = p.fi.fi,
                    ny = p.fi.se,
                    h = p.se;
                ans[h] = min(ans[h], t + abs(nx - x));
            }
            x += g;
            y += g;
            t += g;
            if(x == n)
                tx = -tx;
            if(y == m)
                ty = -ty;
        }
        else if(tx == 1 && ty == -1){
            int g = min(n - x, y);
            for(auto p: v1[x + y]){
                int nx = p.fi.fi,
                    ny = p.fi.se,
                    h = p.se;
                ans[h] = min(ans[h], t + abs(nx - x));
            }
            x += g;
            y -= g;
            t += g;
            if(x == n)
                tx = -tx;
            if(y == 0)
                ty = -ty;
        }
        else if(tx == -1 && ty == 1){
            int g = min(m - y, x);
            for(auto p: v1[x + y]){
                int nx = p.fi.fi,
                    ny = p.fi.se,
                    h = p.se;
                ans[h] = min(ans[h], t + abs(nx - x));
            }
            x -= g;
            y += g;
            t += g;
            if(x == 0)
                tx = -tx;
            if(y == m)
                ty = -ty;
        }
        else if(tx == -1 && ty == -1){
            int g = min(x, y);
            for(auto p: v2[x - y + N]){
                int nx = p.fi.fi,
                    ny = p.fi.se,
                    h = p.se;
                ans[h] = min(ans[h], t + abs(nx - x));
            }
            x -= g;
            y -= g;
            t += g;
            if(x == 0)
                tx = -tx;
            if(y == 0)
                ty = -ty;
        }
    }
    for(int i = 1; i <= k; i++){
        if(ans[i] == 1e18)
            ans[i] = -1;
        //cout << ans[i] << endl;
        pr("%I64d\n", ans[i]);
    }
}