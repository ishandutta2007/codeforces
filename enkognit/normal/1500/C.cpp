#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

int n, m, k, T, kol[1505], a[1501][1501], b[1501][1501];
vector<int> v[1505], ans;
bool tt[1505];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

bool cmp(vector<int> &x,vector<int> &y)
{
    for (int i = 0; i < ans.size(); i++)
        if (x[ans[i]-1]>y[ans[i]-1]) return 0; else
        if (x[ans[i]-1]<y[ans[i]-1]) return 1;
    return 0;
}

void solve()
{
    cin >> n >> m;
    vector<vector<int> > v1, v2, v3;
    vector<int> d;

    for (int i = 1; i <= n; i++)
    {
        d.clear();
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d.pb(a[i][j]);
        }
        v1.pb(d);
        v3.pb(d);
    }

    for (int i = 1; i <= n; i++)
    {
        d.clear();
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
            d.pb(b[i][j]);
        }
        v2.pb(d);
    }
    sort(all(v1));
    sort(all(v2));

    if (v1!=v2)
    {
        cout << "-1\n";
        return;
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (b[i][j]>b[i+1][j]) v[i].pb(j), kol[j]++;
        }
    }


    queue<int> q;

    for (int i = 1; i <= m; i++)
        if (kol[i]==0) q.push(i);

    while (!q.empty())
    {
        int x=q.front();

        q.pop();

        ans.pb(x);

        for (int i = 1; i < n; i++)
        {
            if (b[i][x]!=b[i+1][x] && !tt[i])
            {
                tt[i]=1;
                for (int j = 0; j < v[i].size(); j++)
                {
                    kol[v[i][j]]--;
                    if (kol[v[i][j]]==0) q.push(v[i][j]);
                }
            }
        }
    }

    sort(all(v3), cmp);

    reverse(all(ans));

    //cout << ans.size() << "\n";
    //for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    //cout << "\n";

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v3[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j]!=v3[i-1][j-1])
            {
                cout << "-1\n";
                return;
            }
        }

    //cout << "----\n";

    cout << ans.size() << "\n";
    //reverse(all(ans));
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
01000000
10100000
31100000
00020000
00000000
00000000
00000000
00000000

01100000
10100000
01100000
00100000
00100000
00100000
13112101
00011111
*/