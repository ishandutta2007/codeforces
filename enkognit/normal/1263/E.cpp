#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, j, sum, kol=0, an[10000001];pll d[10000001];
map<string,bool> w;
vector <ll> c[201];

void update(ll h,ll l,ll r,ll x,ll k)
{
    if (l==r)
    {
        d[h]=mp(k,k);
        an[h]=k;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=mp(min(d[h*2].fi,d[h*2].se+d[h*2+1].fi), d[h*2].se+d[h*2+1].se);
    an[h]=max(an[h*2],an[h*2+1]+d[h*2].se);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    ll p=1;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='L') p=max(1ll,p-1);else
        if (s[i]=='R') p++;else
        if (s[i]=='(')
        {
            update(1,1,n,p,1);
        }else
        if (s[i]==')')
        {
            update(1,1,n,p,-1);
        }else update(1,1,n,p,0);
        if (d[1].fi==0 && d[1].se==0) cout << an[1] << " "; else cout << "-1 ";
        //cout << p << "\n";
    }
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/