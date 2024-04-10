#include <bits/stdc++.h>
#pragma GCC optimise("-O3")
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll md1=1e9+7, md2=998244353, p1=4523231, p2=5463161;

ll n, m, T, k, i, j, l, r, ans, kl, o, OK=0, a[1000001];
vector <pll> v;
vector <ll> c[100001];
pll w[100001];
bool tt[100001];
vector <ll> d[1000001];

ll rec(ll l,ll r)
{
    //cout << l << " " << r << "\n";
    if (r-l==0) return 0;
    vector <ll> h1, h2;
    h1.pb(0);
    h2.pb(0);
    vector <ll> v;
    map<pll,ll> w;
    ll md=(l+r)/2;
    //cout << "--\n";
    //cout << l << " " << r << "\n";
    //cout << "-----\n";
    for (int i = md+1; i <= r; i++)
    {
        //cout << i << "\n";
        //cout << h1.back() << " " << h2.back() << "\n";
        if (v.size()==0 || v.back()!=a[i])
        {
            v.pb(a[i]);
            h1.pb((h1.back()*p1%md1+a[i])%md1);
            h2.pb((h2.back()*p2%md2+a[i])%md2);
        }else
        {
            v.pop_back();
            h1.pop_back();
            h2.pop_back();
        }
        w[mp(h1.back(),h2.back())]++;
    }
    v.clear();
    h1.clear();
    h1.pb(0);
    h2.clear();
    h2.pb(0);
    ll ans=0;
    //cout << "---\n";
    for (int i = md; i >= l; i--)
    {
        //cout << h1.back() << " " << h2.back() << "\n";
        if (v.size()==0 || v.back()!=a[i])
        {
            v.pb(a[i]);
            h1.pb((h1.back()*p1+a[i])%md1);
            h2.pb((h2.back()*p2+a[i])%md2);
        }else
        {
            v.pop_back();
            h1.pop_back();
            h2.pop_back();
        }
        ans+=w[mp(h1.back(),h2.back())];
    }
    //cout << "-----\n";
    return rec(l,md)+rec(md+1,r)+ans;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << rec(1,n) << "\n";
}

int main()
{
    //freopen("travelator.in","r",stdin);
    //freopen("travelator.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}