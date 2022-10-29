#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, A, B, C, y, kol, tt[1000001];
bool d[35][1000001];
string s;

void update(ll m,ll h,ll l,ll r,ll x,bool t)
{
    if (l==r){d[m][h]=t;return;}
    ll w=(l+r)/2;
    if (x<=w) update(m,h*2,l,w,x,t); else update(m,h*2+1,w+1,r,x,t);
    d[m][h]=(d[m][h*2]|d[m][h*2+1]);
}

bool get(ll m,ll h,ll l,ll r,ll x,ll y)
{
    //if (d[m][h])cout << m <<" " << x << " " << y << "\n";
    if (x>y) return 0;
    if (l==x && y==r) {return d[m][h];}
    ll w=(l+r)/2;
    bool p=(get(m,h*2,l,w,x,min(y,w))|get(m,h*2+1,w+1,r,max(x,w+1),y));
    return p;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n=s.size();
    s=' '+s;
    ll q;
    cin >> q;
    for (int i = 1; i <= n; i++) update(s[i]-'a',1,1,n,i,1);
    for (it = 0; it < q; it++)
    {
        ll x, y, h;
        char c;
        cin >> x >> y;
        if (x==1)
        {
            cin >> c;
            update(s[y]-'a',1,1,n,y,0);
            s[y]=c;
            update(s[y]-'a',1,1,n,y,1);
        }else
        if (x==2)
        {
            cin >> h;
            ll ans=0;
            for (int i = 0; i <= 'z'-'a'; i++)
            {
                ans+=(int)get(i,1,1,n,y,h);
            }
            cout << ans << "\n";
        }
    }
}