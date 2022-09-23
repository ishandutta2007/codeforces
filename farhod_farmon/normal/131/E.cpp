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

vector < pair < int, int > > c[N], r[N], d1[N], d2[N];
int n, m, d[10], f[N];

void F(vector < pair < int, int > > v)
{
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++){
        f[v[i].se]++;
        f[v[i + 1].se]++;
    }
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
        c[x].pb({y, i});
        r[y].pb({x, i});
        d1[x + y].pb({x, i});
        d2[x - y + n].pb({x, i});
    }
    for(int i = 0; i < N; i++){
        if(!c[i].empty())
            F(c[i]);
        if(!r[i].empty())
            F(r[i]);
        if(!d1[i].empty())
            F(d1[i]);
        if(!d2[i].empty())
            F(d2[i]);
    }
    for(int i = 1; i <= m; i++)
        d[f[i]]++;
    for(int i = 0; i <= 8; i++)
        pr("%d ", d[i]);
}