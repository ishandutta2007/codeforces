#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

const ll MOD=1e9+7;
ll n, m, i, j, k, t, I, a[500001];
vector <ll> v, q;

ll log2(ll h)
{
    ll o=0, p=h, tt=0;
    while (p>1)
    {
        if (p%2) tt=1;
        p/=2;
        o++;
    }
    return o+tt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> n >> I;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    ll k=1;
    v.pb(1);
    for (int i = 1; i < n; i++)
        if (a[i]!=a[i-1]) k++, v.pb(1); else v[v.size()-1]++;
    ll ans=1e18, p=0, e=0;
    I*=8;
    q.pb(0);
    for (int i = 0; i < v.size(); i++) q.pb(q[q.size()-1]+v[i]);

    //for (int i = 0; i < q.size(); i++) cout << q[i] << " ";
    //cout << "\n";

    ll r=0;

    for (int l = 0; l < q.size()-1; l++)
    {
        while (r+1<q.size() && log2(r+1-l)*n<=I) r++;
        //cout << l << " " << r << "\n";
        ans=min(q[l]+q[q.size()-1]-q[r],ans);
    }
    cout << ans;
}