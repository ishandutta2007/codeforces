#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector<int>
#define vl              vector<ll>
#define pii             pair<int,int>
#define pil             pair<int, ll>
#define pll             pair<ll, ll>
#define pli             pair<ll, int>
#define pb(v, a)        v.push_back(a)
#define mp(a, b)        make_pair(a, b)
#define MOD             1000000007
#define rep(i, a, b)    for(i=a; i<=b; ++i)
#define rrep(i, a, b)   for(i=a; i>=b; --i)
#define si(x)           do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define sl(a)           scanf("%lld", &a)
#define pi(a)           printf("%d", a)
#define pl(a)           printf("%lld", a)
#define pn              printf("\n")
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
vector<int> adj[500005];
vector<int> level[500005][26];
int timer, st_time[500005], end_time[500005];
bool visited[500005];
char str[500005];
void dfs(int nd, int lev)
{
    visited[nd] = true;
    st_time[nd] = ++timer;
    level[lev][str[nd] - 'a'].push_back(st_time[nd]);
    int i;
    rep(i, 0, (int)(adj[nd].size() - 1))
    {
        int to = adj[nd][i];
        if(!visited[to])
            dfs(to, lev + 1);
        int j;
    }
    end_time[nd] = timer;
}
int main()
{
    timer = 0;
    int n, q;
    si(n); si(q);
    int i, x;
    rep(i, 2, n)
    {
        si(x);
        adj[i - 1].push_back(x - 1);
        adj[x - 1].push_back(i - 1);
    }
    scanf("%s", str);
    dfs(0, 1);
    while(q--)
    {
        int v, h;
        si(v); si(h);
        v--;
        int odd_occur = 0;
        rep(i, 0, 25)
        {
            int val = upper_bound(level[h][i].begin(), level[h][i].end(), end_time[v]) - lower_bound(level[h][i].begin(), level[h][i].end(), st_time[v]);
            if(val & 1)
                odd_occur++;
            // if(odd_occur > 1)
            //  break;
        }
        if(odd_occur <= 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}