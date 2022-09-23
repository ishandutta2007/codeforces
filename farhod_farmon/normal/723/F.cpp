#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n, m;
int s, t, ds, dt;
int p[N];
vector < pair < int, int > > edges, ans;
vector < int > v[N];
bool us[N], ut[N], uo[N];
vector < int > ss, st, so;

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y;
        sc("%d%d", &x, &y);
        edges.pb({x, y});
    }
    for(int i = 1; i <= n; i++)
        p[i] = i;
    sc("%d%d%d%d", &s, &t, &ds, &dt);
    for(int i = 0; i < m; i++){
        int x = edges[i].fi,
            y = edges[i].se;
        if(x == s || x == t || y == s || y == t){
            v[x].pb(y);
            v[y].pb(x);
            continue;
        }
        int px = get(x),
            py = get(y);
        if(px == py)
            continue;
        p[px] = py;
        ans.pb({x, y});
    }
    for(int i = 0; i < v[s].size(); i++){
        int x = v[s][i];
        us[get(x)] = true;
    }
    for(int i = 0; i < v[t].size(); i++){
        int x = v[t][i];
        ut[get(x)] = true;
    }
    for(auto x: v[s]){
        if(ut[(get(x))] || !us[get(x)] || x == t || get(x) == s)
            continue;
        if(!ds)
            break;
        ds--;
        ans.pb({s, x});
        p[get(x)] = s;
        us[get(x)] = false;
    }
    for(auto x: v[t]){
        if(us[get(x)] || !ut[get(x)] || get(x) == s || get(x) == t)
            continue;
        if(!dt)
            break;
        dt--;
        ans.pb({t, x});
        p[get(x)] = t;
        ut[get(x)] = false;
    }
    bool fff = false;
    for(auto x: v[s]){
        if(x == t){
            fff = true;
            continue;
        }
        if(get(x) == get(s))
            continue;
        if(!ds)
            break;
        ds--;
        ans.pb({s, x});
        p[get(x)] = get(s);
        us[get(x)] = false;
    }
    for(auto x: v[t]){
        if(x == s)
            continue;
        if(get(x) == get(t))
            continue;
        if(!dt)
            break;
        dt--;
        ans.pb({t, x});
        p[get(x)] = get(t);
        ut[get(x)] = false;
    }
    if(fff && get(s) != get(t)){
        if(ds && dt){
            p[get(s)] = get(t);
            ans.pb({s, t});
        }
    }
    if(get(s) != get(t)){
        pr("No\n");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(get(i) != get(s)){
            pr("No\n");
            return 0;
        }
    }
    pr("Yes\n");
    for(int i = 0; i < ans.size(); i++)
        pr("%d %d\n", ans[i].fi, ans[i].se);
}