#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 500500;

using namespace std;

map < int, int > p, q;
set < int > s;
int n, a[N];
pair < int, int > t[4 * N];
vector < int > v[N];
vector < pair < int, int > > ans;

pair < int, int > comb(pair < int, int > x, pair < int, int > y)
{
    if(y.fi > x.fi)
        return y;
    return x;
}

void upd(int x, int l, int r, int g, int y, int h)
{
    if(l == r){
        t[x] = {h, y};
        return;
    }
    int m = (l + r) / 2;
    if(g <= m)
        upd(x * 2, l, m, g, y, h);
    else
        upd(x * 2 + 1, m + 1, r, g, y, h);
    t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

pair < int, int > get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return {0, 0};
    if(l == tl && r == tr)
        return t[x];
    int m = (l + r) / 2;
    return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    int g = 0;
    for(auto &x: s){
        p[x] = ++g;
        q[g] = x;
    }
    int last = 1;
    for(int i = 1; i <= n; i++){
        a[i] = p[a[i]];
        v[a[i]].pb(i);
        if(v[a[i]].size() == 4){
            ans.pb({a[i], a[i]});
            while(last <= i){
                v[a[last]].clear();
                last++;
            }
            continue;
        }
        for(int j = 0; j + 1 < v[a[i]].size(); j++){
            int h = v[a[i]][j];
            pair < int, int > r = get(1, 1, n, last, h - 1);
            if(h > last && h < r.fi){
                ans.pb({r.se, a[i]});
                while(last <= i){
                    v[a[last]].clear();
                    last++;
                }
                break;
            }
            if(last > i)
                break;
        }
        for(int j = 0; j + 1 < v[a[i]].size(); j++)
            upd(1, 1, n, v[a[i]][j], a[i], i);
    }
    cout << ans.size() * 4 << endl;
    for(int i = 0; i < ans.size(); i++){
        int x = ans[i].fi,
            y = ans[i].se;
        x = q[x];
        y = q[y];
        cout << x << " " << y << " " << x << " " << y << " ";
    }
}