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

ll n, m, k, l, r, T, i, kl, j, x, a[1000001];
string s;
vector<pair<pll,ll> > c[505][505];
string v;
bool tt[5000001];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i>1) c[i][j].pb(mp(mp(i-1,j),++kl));
            if (i<n) c[i][j].pb(mp(mp(i+1,j),++kl));
            if (j>1) c[i][j].pb(mp(mp(i,j-1),++kl));
            if (j<m) c[i][j].pb(mp(mp(i,j+1),++kl));
        }
    //cout << kl << "\n";
    if (k>kl) {cout << "NO\n";return;}
    //cout << "----\n";
    v.clear();
    vector<pll> st;
    st.pb(mp(1,1));
    ll x, y;
    vector<pll> w;
    while (st.size())
    {
        bool t=0;
        x=st.back().fi, y=st.back().se;
        for (int i = 0; i < c[x][y].size(); i++)
            if (!tt[c[x][y][i].se])
            {
                tt[c[x][y][i].se]=1;
                t=1;
                //w.pb(mp(x,y));
                st.pb(mp(c[x][y][i].fi.fi,c[x][y][i].fi.se));
                break;
            }
        //3cout << st.back().fi << " " << st.back().se << " " << t << "\n";
        if (!t) {w.pb(mp(x,y));st.pop_back();}
    }
    //cout << w.size() << "\n";
    //cout << w[0].fi << " " << w[0].se << "\n";
    for (int i = 1; i < w.size(); i++)
    {
        //cout << w[i].fi << " " << w[i].se << "\n";
        if (w[i-1].fi<w[i].fi) v+='D'; else
        if (w[i-1].fi>w[i].fi) v+='U'; else
        if (w[i-1].se<w[i].se) v+='R'; else
        if (w[i-1].se>w[i].se) v+='L';
        if (v.size()==k) break;
    }
    //cout << v << "\n";
    vector<pair<ll,string> > q;
    if (v.size()<k) {cout << "NO\n";return;}
    for (int i = 0; i < v.size();)
    {
        //cout << i << " : ";
        ll mx=i+1, p=1;
        for (int j = 4; j > 0; j--)
        {
            ll o=i;
            while (1)
            {
                //cout << o < "\n";
                if (o+j+j-1>=v.size()) break;
                bool t=1;
                for (int u = o; u < o+j; u++)
                    if (v[u]!=v[u+j]) {t=0;break;}
                //if (j==1) cout << j << " " << o << " " << t << "\n";
                if (t)
                {
                    o+=j;
                    //cout << " " << mx << " - " << o+j << " " << j << "\n";
                    if (mx<o+j) mx=o+j, p=j;
                } else break;
            }
        }
        //cout << " " << mx << " - " << p << "\n";
        string d="";
        for (int j = i; j < i+p; j++) d+=v[j];
        q.pb(mp((mx-i)/p,d));
        i=mx;
    }
    cout << "YES\n";
    cout << q.size() << "\n";
    for (int i = 0; i < q.size(); i++)
        cout << q[i].fi << " " << q[i].se << "\n";
    //cout << q.size() << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
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