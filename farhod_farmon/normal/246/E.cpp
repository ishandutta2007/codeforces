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
const int magic = sqrt(N);

using namespace std;

map < string, int > numb;
vector < int > v[N], level[N];
vector < pair < pair < int, int >, int > > query[N];
int a[N];
int c[N];
int dep[N];
int tin[N];
int tout[N];
int n;
int ans[N];
int tim;

void dfs(int x)
{
    tin[x] = ++tim;
    level[dep[x]].pb(tin[x]);
    c[tin[x]] = a[x];
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(y == x)
            continue;
        dep[y] = dep[x] + 1;
        dfs(y);
    }
    tout[x] = tim;
}

bool cmp(pair < pair < int, int >, int > x, pair < pair < int, int >, int > y)
{
    if(x.fi.fi / magic == y.fi.fi / magic)
        return x.fi.se < y.fi.se;
    return x.fi.fi < y.fi.fi;
}

pair < int, int > get(int tl, int tr, int g)
{
    int l = 0,
        r = level[g].size() - 1;
    if(r == -1)
        return {-1, -1};
    while(l < r){
        int m = (l + r) / 2;
        if(level[g][m] < tl)
            l = m + 1;
        else
            r = m;
    }
    int f1 = l;
    r = level[g].size() - 1;
    while(l < r){
        int m = (l + r) / 2 + 1;
        if(level[g][m] <= tr)
            l = m;
        else
            r = m - 1;
    }
    int f2 = l;
    if(tl <= level[g][f1] && level[g][f2] <= tr)
        return {f1, f2};
    return {-1, -1};
}

int us[N];
int cnt;

void add(int x)
{
    x = c[x];
    us[x]++;
    if(us[x] == 1)
        cnt++;
}

void sub(int x)
{
    x = c[x];
    if(us[x] == 1)
        cnt--;
    us[x]--;
}

void solve(int g)
{
    int l = 0,
        r = 0;
    add(level[g][0]);
    for(int i = 0; i < query[g].size(); i++){
        int tl = query[g][i].fi.fi,
            tr = query[g][i].fi.se,
            h = query[g][i].se;
        while(tl > l)
            sub(level[g][l++]);
        while(l > tl)
            add(level[g][--l]);
        while(tr > r)
            add(level[g][++r]);
        while(r > tr)
            sub(level[g][r--]);
        ans[h] = cnt;
    }
    for(int i = 0; i < level[g].size(); i++)
        us[c[level[g][i]]] = 0;
    cnt = 0;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int g = 1, root;
    for(int i = 1; i <= n; i++){
        string s;
        int p, x;
        cin >> s >> p;
        if(numb[s] == 0)
            numb[s] = g++;
        x = numb[s];
        a[i] = x;
        v[p].pb(i);
    }
    for(int i = 0; i < v[0].size(); i++)
        dfs(v[0][i]);
    //dfs(root);
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        y = dep[x] + y;
        auto ff = get(tin[x], tout[x], y);
        if(ff.fi == -1)
            continue;
        query[y].pb({ff, i});
    }
    for(int i = 1; i <= n; i++){
        if(level[i].empty())
            continue;
        sort(query[i].begin(), query[i].end(), cmp);
        solve(i);
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}