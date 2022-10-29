#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

const ll MOD=998244353;

ll n, m, i, j, x, k;
unsigned ll fact[300005], ans=1;
vector <unsigned ll> c[300005];
bool tt[300005];

ll dfs(ll h)
{
    tt[h]=1;
    unsigned ll q=0;
    for (int i = 0; i < c[h].size(); i++) if (!tt[c[h][i]]) q+=dfs(c[h][i]);
    if (c[h].size())
    {
        ans=(ans*fact[c[h].size()])%MOD;
        ans%=MOD;
    }
    return (q+1)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    //ll x, y, z;
    cin >> n;
    fact[0]=1;
    fact[1]=1;
    for (int i = 2; i <= n+2; i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    //cout << fact[10];
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ans=1;
    ll o;
    o=dfs(1);
    if (o!=n)while(1);
    cout << (ans*n)%MOD;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/