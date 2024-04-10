#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, x, y, a[1000001], dk[1000001][2];
ll tb[1000001], ta[1000001];
vector <ll> an;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

vector<pll> v;

int main()
{
    //ios::sync_with_stdio(0);
    cin >> n;
    vector <ll> v, va, vb, vv;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x!=0) ta[i]=x, tb[x]=i; else v.pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (ta[i] && !tb[i]) vb.pb(i); else
        if (!ta[i] && tb[i]) va.pb(i); else
        if (!ta[i] && !tb[i]) vv.pb(i);
    //cout << va.size() << " " << vb.size() << "\n";
    if (va.size()==0 && vb.size()==0)
    {
        for (int i = 0; i < vv.size()-1; i++) ta[vv[i]]=vv[i+1];
        ta[vv.back()]=vv[0];
        for (int i = 1; i <= n; i++) cout << ta[i] << " ";
        exit(0);
    }
    for (int i = 0; i < min(va.size()-1,vb.size()-1); i++)
    {
        ta[va[i]]=vb[i];
    }
    if (vv.size())
    {
        ta[va.back()]=vv[0];
        for (int i = 1; i < vv.size(); i++) ta[vv[i-1]]=vv[i];
        ta[vv.back()]=vb.back();
    }else ta[va.back()]=vb.back();
    for (int i = 1; i <= n; i++) cout << ta[i] << " ";
    return 0;
}