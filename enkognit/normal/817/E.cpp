#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, y, kol=1;
ll b[3000001][2];
ll d[3000001];

vector <bool> getmask(ll h)
{
    ll z=h;
    vector <bool> p;
    while (z)
    {
        p.pb(z%2);
        z/=2;
    }
    while (p.size()<30)
        p.pb(0);
    reverse(p.begin(),p.end());
    return p;
}

void update(vector <bool> p,ll h,ll k,ll x)
{
    if (k==30)
    {
        d[h]+=x;
        return;
    }
    if (b[h][p[k]]==0)
    {
        kol++;
        b[h][p[k]]=kol;
    }
    update(p,b[h][p[k]],k+1,x);
    d[h]=d[b[h][0]]+d[b[h][1]];
}

ll get(vector <bool> x, vector <bool> y, ll h, ll k)
{
    if (k==30) return 0;
    ll w=0;
    if (b[h][0]>0)
    {
        if ((0^x[k])<y[k]) w+=d[b[h][0]]; else
        if ((0^x[k])==y[k]) w+=get(x,y,b[h][0],k+1);
    }
    if (b[h][1]>0)
    {
        if ((1^x[k])<y[k]) w+=d[b[h][1]];else
        if ((1^x[k])==y[k]) w+=get(x,y,b[h][1],k+1);
    }
    //cout << x[k] << " " << y[k] << " " << k << "\n";
    return w;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll x;
            cin >> x;
            update(getmask(x),1,0,1);
            //vector <bool> u=getmask(x);
            //for (int i = 0; i < u.size(); i++) cout << u[i];
            //cout << "\n";
        }else
        if (t==2)
        {
            ll x;
            cin >> x;
            update(getmask(x),1,0,-1);
        }else
        {
            ll x, y;
            cin >> x >> y;
            cout << get(getmask(x),getmask(y),1,0) << "\n";
            //vector <bool> u=getmask(x);
            //for (int i = 0; i < u.size(); i++) cout << u[i];
            //cout << "\n";
            //u=getmask(y);
            //for (int i = 0; i < u.size(); i++) cout << u[i];
            //cout << "\n";
        }
    }
    return 0;
}