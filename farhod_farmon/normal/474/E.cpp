#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, d, L;
int dp[N];
int P[N];
long long h[N];
map < long long, bool > used;
pair < long long, long long > p[N], t[4 * N];

int id(long long x, int g)
{
    int l = 1,
        r = L;
    while(l < r){
        int m = (l + r) / 2;
        if(g){
            if(p[m].fi < x)
                l = m + 1;
            else
                r = m;
        }
        else{
            if(p[m + 1].fi <= x)
                l = m + 1;
            else
                r = m;
        }
    }
    if(g && p[l].fi >= x)
        return l;
    if(!g && x >= p[l].fi)
        return l;
    return -1;
}

void upd(int x, int l, int r, int g, pair < long long, long long > y)
{
    if(l == r){
        t[x] = max(t[x], y);
        return;
    }
    int m = (l + r) / 2;
    if(g <= m)
        upd(x * 2, l, m, g, y);
    else
        upd(x * 2 + 1, m + 1, r, g, y);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}

pair < long long, long long > get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return {0, 0};
    if(tl == l && tr == r)
        return t[x];
    int m = (l + r) / 2;
    return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &d);
    for(int i = 1; i <= n; i++){
        sc("%I64d", &h[i]);
        if(used[h[i]])
            continue;
        used[h[i]] = true;
        p[++L] = {h[i], i};
    }
    sort(p + 1, p + L + 1);
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        int a = id(h[i] - d, 0),
            b = id(h[i] + d, 1);
        if(a != -1){
            pair < long long, long long > j = get(1, 1, n, 1, a);
            if(dp[j.se] + 1 > dp[i]){
                dp[i] = dp[j.se] + 1;
                P[i] = j.se;
            }
        }
        if(b != -1){
            pair < long long, long long > j = get(1, 1, n, b, n);
            if(dp[j.se] + 1 > dp[i]){
                dp[i] = dp[j.se] + 1;
                P[i] = j.se;
            }
        }
        upd(1, 1, n, id(h[i], 0), {dp[i], i});
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(dp[i] > dp[ans])
            ans = i;
    }
    vector < int > v;
    for(int i = dp[ans]; i >= 1; i--){
        v.pb(ans);
        ans = P[ans];
    }
    pr("%d\n", v.size());
    for(int i = v.size() - 1; i >= 0; i--)
        pr("%d ", v[i]);
}