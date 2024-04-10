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

int n, m, p;
int a[N];
int b[N];
int cnt;
vector < int > ans;
map < int, int > used;

void add(int x)
{
    if(used.find(x) == used.end())
        return;
    used[x]--;
    if(used[x] == 0)
        cnt++;
    if(used[x] == -1)
        cnt--;
}

void sub(int x)
{
    if(used.find(x) == used.end())
        return;
    used[x]++;
    if(used[x] == 0)
        cnt++;
    if(used[x] == 1)
        cnt--;
}

void solve(int x)
{
    vector < int > g;
    for(int i = x; i <= n; i += p)
        g.pb(a[i]);
    if(g.size() < m)
        return;
    for(int i = 0; i < m; i++)
        used[b[i + 1]]++;
    for(int i = 0; i < m; i++)
        add(g[i]);
    if(cnt == used.size())
        ans.pb(x);
    for(int i = m; i < g.size(); i++){
        add(g[i]);
        sub(g[i - m]);
        if(cnt == used.size())
            ans.pb((i - m + 1) * p + x);
    }
    for(int i = 0; i < m; i++)
        used[b[i + 1]] = 0;
    cnt = 0;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        sc("%d", &b[i]);
    for(int i = 1; i <= p; i++)
        solve(i);
    sort(ans.begin(), ans.end());
    pr("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        pr("%d ", ans[i]);
}