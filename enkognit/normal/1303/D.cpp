#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 shue_ppsh
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, a[1000001], pp[100001];
string s, d;
ll tt[1001];
vector<ll> c[1001];

void dfs(int h)
{
    tt[h]=1;
    d+=h;
    //cout << (char)h;
    kl++;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) dfs(c[h][i]);
}

void solve()
{
    cin >> m >> n;
    for (int i = 0; i < 30; i++)
    {
        a[i]=0;
        tt[i]=0;
        pp[i]=0;
    }
    ll p=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p+=a[i];
        ll x=a[i], j=0;
        while (x)
        {
            x/=2;
            j++;
        }
        tt[j-1]++;
        //cout << j-1 << "\n";
        //cout << j-1 << " ";
        a[i]=0;
    }
    //cout << "\n";
    if (p<m){cout << "-1\n";return;}
    ll x=m, j=0;
    vector<ll> v;
    while (x)
    {
        if (x%2) {v.pb(j);}
        j++;
        x/=2;
    }
    reverse(all(v));
    for (int i = 0 ;i < v.size(); i++) {a[v[i]]=1;}
    //cout << "\n";
    ll kl=0, ans=0;
    for (int i = 0; i < 30; i++)
    {
        kl+=tt[i];
        //cout << i << " : " << kl << " " << a[i] << "\n";
        if (a[i])
        {
            if (kl>0)
            {
                kl--, a[i]=0;
            }else
            {
                for (int j = i+1; j < 30; j++)
                    if (tt[j])
                    {
                        tt[j]--;
                        ans+=j-i;
                        //cout << " - " << j << " " << i << "\n";
                        for (int u = i; u < j; u++) tt[u]++;
                        break;
                    }
                kl+=tt[i];
                kl--, a[i]=0;
            }
        }
        tt[i]=kl%2;
        kl/=2;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/