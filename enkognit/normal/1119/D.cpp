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

ll n, m, l, r, x, y, pr[200001];
vector <ll> a,v;
bool t[300001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    v.pb(0);
    for (int i = 1; i < a.size(); i++) v.pb(a[i]-a[i-1]);
    sort(v.begin(),v.end());
    pr[0]=0;

    for (int i = 1; i < v.size(); i++) pr[i]=pr[i-1]+v[i];

    cin >> m;
    for (int j = 0; j < m; j++)
    {
        ll l, r;
        cin >> l >> r;
        ll p = r - l + 1;
        l = 0, r=v.size()-1;
        while (l < r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (v[w]>p) r=w-1; else l=w;
        }
        cout << pr[l]+(v.size()-l)*p << "\n";
    }
    return 0;
}