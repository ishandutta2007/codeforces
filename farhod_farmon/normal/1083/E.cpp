#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1000010;

using namespace std;

int n;
pair < pair < int, int >, long long > p[N];
vector < int > v;
vector < pair < long long, long long > > g;

long double inter(int i, int j)
{
        return (long double)(g[j].se - g[i].se) / (g[i].fi - g[j].fi);
}

int now = 0;

long long f(int i, long long x)
{
        return g[i].fi * x + g[i].se;
}

long long get(long long x)
{
        if(v.empty()){
                return 0;
        }
        now = min(now, (int)v.size() - 1);
        while(now + 1 < v.size() && f(v[now], x) < f(v[now + 1], x)){
                now++;
        }
        return f(v[now], x);
}

void upd(long long b, long long k)
{
        g.push_back({k, b});
        int id = g.size() - 1, n = v.size();
        while(n > 1 && inter(v[n - 2], id) < inter(v[n - 2], v[n - 1])){
                v.pop_back();
                n--;
        }
        v.push_back(id);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
        }
        sort(p + 1, p + n + 1);
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                long long x = p[i].fi.fi, y = p[i].fi.se, a = p[i].se;
                long long d = max(0ll, get(-y)) + x * y - a;
                ans = max(ans, d);
                upd(d, x);
        }
        cout << ans << "\n";
}