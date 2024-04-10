#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, W, l, r, ans, t, k, a[1000003];
ll tl[1000001], tr[1000001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    //vector <ll> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tr[a[i]]=i;
        if (!tl[a[i]]) tl[a[i]]=i;
    }
    ll j=1;
    bool tt=0;
    vector <ll> v, p;
    v.pb(0);
    p.pb(0);
    for (int i = 0; i <= n; i++)
    {
        if (a[i]==j)
        {
            if (i==tl[a[i]]) tt=1;
            if (tt && i==tr[a[i]]) {v.pb(i);j++, tt=0;}
        }
        while (tl[j]==0 && j<=m) {v.pb(i);j++;}
    }
    j=m;
    tt=0;
    for (int i = n+1; i > 0; i--)
    {
        if (a[i]==j)
        {
            if (i==tr[a[i]]) tt=1;
            if (tt && i==tl[a[i]]) {p.pb(i);j--, tt=0;}
        }
        while (tl[j]==0 && j>0) {p.pb(i);j--;}
    }
    sort(v.begin()+1,v.end());
    sort(p.begin()+1,p.end());
    reverse(p.begin()+1,p.end());
    //cout << "\n";
    //for (int i = 1; i < v.size(); i++) cout << v[i] << " " << i << "\n";
    //cout << "\n";
    //for (int i = 1; i < p.size(); i++) cout << p[i] << " " << m-i+1 << "\n";
    //cout << "\n";
    ans+=v.size()+p.size()-1;
    if (v.size()-1==m && p.size()-1==m) ans-=2;
    for (int i = 1; i < p.size(); i++)
    {
        ll o=m-i+1;
        ll l=0, r=min((ll)v.size()-1,o-2);
        while (l<r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (p[i]<=v[w]) r=w-1; else l=w;
        }
        ans+=l;
    }
    cout << ans;
    return 0;
}