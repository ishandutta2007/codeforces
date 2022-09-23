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

int n, k, s, t;
int c[N];
int v[N];
vector < int > g;

bool f(int x)
{
    long long cnt = s + s;
    for(int i = 0; i + 1 < g.size(); i++){
        if(g[i + 1] - g[i] > x)
            return false;
        int l = x - (g[i + 1] - g[i]);
        cnt -= min(g[i + 1] - g[i], l);
    }
    return cnt <= t;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d%d%d", &n, &k, &s, &t);
    for(int i = 1; i <= n; i++)
        sc("%d%d", &c[i], &v[i]);
    g.pb(0);
    g.pb(s);
    for(int i = 1; i <= k; i++){
        int x;
        sc("%d", &x);
        g.pb(x);
    }
    sort(g.begin(), g.end());
    int l = 0,
        r = 1e9 + 1;
    while(l < r){
        int m = (l + r) / 2;
        if(f(m))
            r = m;
        else
            l = m + 1;
    }
    int ans = 1e9 + 1;
    for(int i = 1; i <= n; i++)
        if(v[i] >= l)
            ans = min(ans, c[i]);
    if(ans == 1e9 + 1)
        ans = -1;
    pr("%d\n", ans);
}