#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll long long

const int N = 100100;
const long long mod = 1e15 + 3;

using namespace std;

int n;
int k;
int x[N];
int r[N];
int f[N];
int in[N];
pair < int, int > p[N];
vector < int > t[N / 10];
vector < pair < int, int > > v[N / 10];

void upd(int tp, int pos)
{
    for(; pos < t[tp].size(); pos += pos & -pos)
        t[tp][pos]++;
}

int gs(int tp, int pos)
{
    int cnt = 0;
    for(; pos > 0; pos -= pos & -pos)
        cnt += t[tp][pos];
    return cnt;
}

int get1(int tp, int g)
{
    int tl = 0,
        tr = v[tp].size() - 1;
    while(tl < tr){
        int m = (tl + tr) / 2;
        if(g <= v[tp][m].fi)
            tr = m;
        else
            tl = m + 1;
    }
    return tl;
}

int get2(int tp, int g)
{
    int tl = 0,
        tr = v[tp].size() - 1;
    while(tl < tr){
        int m = (tl + tr) / 2;
        if(v[tp][m + 1].fi <= g)
            tl = m + 1;
        else
            tr = m;
    }
    return tl;
}

int sol(int tp, int tl, int tr)
{
    if(v[tp].empty())
        return 0;
    int in1 = get1(tp, tl) + 1,
        in2 = get2(tp, tr) + 1;
    return gs(tp, in2) - gs(tp, in1 - 1);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> r[i] >> f[i];
        v[f[i]].pb({x[i], i});
        p[i] = {r[i], i};
    }
    for(int i = 1; i < N / 10; i++){
        if(v[i].empty())
            continue;
        v[i].pb({0, 0});
        v[i].pb({1e9 + 1, 0});
        sort(v[i].begin(), v[i].end());
        t[i].resize(v[i].size() + 3, 0);
        for(int j = 0; j < v[i].size(); j++)
            in[v[i][j].se] = j + 1;
    }
    sort(p + 1, p + n + 1);
    ll ans = 0;
    for(int i = n; i >= 1; i--){
        int h = p[i].se;
        for(int j = max(f[h] - k, 1); j <= f[h] + k; j++)
            ans += sol(j, x[h] - r[h], x[h] + r[h]);
        upd(f[h], in[h]);
    }
    cout << ans << endl;
}