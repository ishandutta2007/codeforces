#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400400;

using namespace std;

long long n;
long long st;
long long a[N];
long long t[N];
long long ans[N];
map < long long, int > id;
vector < long long > order;
vector < pair < long long , long long > > v[N];

void dfs(long long x, long long p, long long g)
{
    int l = 0,
        r = order.size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(order[m + 1] < g - a[x])
            l = m + 1;
        else
            r = m;
    }
    t[order.size() - 1]++;
    t[l]--;
    order.pb(g);
    for(auto y: v[x]){
        if(y.fi != p){
            dfs(y.fi, x, g + y.se);
        }
    }
    ans[x] = t[order.size() - 1];
    order.pop_back();
    t[order.size() - 1] += t[order.size()];
    t[order.size()] = 0;
}


int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%I64d", &n);
    for(int i = 1; i <= n; i++)
        sc("%I64d", &a[i]);
    for(int i = 2; i <= n; i++){
        long long p, w;
        sc("%I64d%I64d", &p, &w);
        v[p].pb({i, w});
        v[i].pb({p, w});
    }
    order.pb(-1e18);
    dfs(1, -1, 0);
    for(int i = 1; i <= n; i++)
        pr("%I64d ", ans[i]);
}