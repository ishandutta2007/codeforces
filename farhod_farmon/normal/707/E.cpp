#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, m, k;
lli ans[2020];
vector < pair < pair < int, int >, int > > v[2020];
vector < pair < int, pair < pair < int, int >, pair < int, int > > > > query[2020];
lli t[2020][2020];

lli gety(int x, int y)
{
    lli cnt = 0;
    while(y){
        cnt += t[x][y];
        y -= y & -y;
    }
    return cnt;
}

lli get(int x, int y)
{
    lli cnt = 0;
    while(x){
        cnt += gety(x, y);
        x -= x & -x;
    }
    return cnt;
}

lli updy(int x, int y, int w)
{
    while(y <= m){
        t[x][y] += w;
        y += y & -y;
    }
}

lli upd(int x, int y, int w)
{
    while(x <= n){
        updy(x, y, w);
        x += x & -x;
    }
}

int sz;
bool used[2020];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    sc("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        int len;
        sc("%d", &len);
        for(int j = 1; j <= len; j++){
            int x, y, w;
            sc("%d%d%d", &x, &y, &w);
            v[i].pb({{x, y}, w});
        }
    }
    int q;
    sc("%d", &q);
    for(int i = 1; i <= q; i++){
        char c[111];
        sc("%s", &c);
        if(c[0] == 'A'){
            int x1, x2, y1, y2;
            sc("%d%d%d%d", &x1, &y1, &x2, &y2);
            sz++;
            for(int j = 1; j <= k; j++)
                if(!used[j])
                    query[j].pb({sz, {{x1, y1}, {x2, y2}}});
        }
        else{
            int x;
            sc("%d", &x);
            used[x] = 1 - used[x];
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < v[i].size(); j++)
            upd(v[i][j].fi.fi, v[i][j].fi.se, v[i][j].se);
        for(int j = 0; j < query[i].size(); j++){
            int h = query[i][j].fi;
            int x1 = query[i][j].se.fi.fi;
            int y1 = query[i][j].se.fi.se;
            int x2 = query[i][j].se.se.fi;
            int y2 = query[i][j].se.se.se;
            ans[h] += get(x2, y2);
            ans[h] -= get(x1 - 1, y2);
            ans[h] -= get(x2, y1 - 1);
            ans[h] += get(x1 - 1, y1 - 1);
        }
        for(int j = 0; j < v[i].size(); j++)
            upd(v[i][j].fi.fi, v[i][j].fi.se, -v[i][j].se);
    }
    for(int i = 1; i <= sz; i++)
        pr("%I64d\n", ans[i]);
}