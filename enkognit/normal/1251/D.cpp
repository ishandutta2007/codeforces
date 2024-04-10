#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j;
pll d[2000001];
string s;
string v1, v0;
bool tt[1000001], q[1000001];

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector <pll> v;
        for (int i = 0; i < n; i++)
        {
            ll l, r;
            cin >> l >> r;
            v.pb(mp(l,r));
        }
        ll l=0, r=1e9;
        while (l<r)
        {
            ll w=(l+r+1)/2;
            vector <pll> v0, v1, v2;
            for (int i = 0; i < n; i++)
            {
                if (v[i].se<w) v0.pb(v[i]); else
                if (v[i].fi>w) v2.pb(v[i]); else
                v1.pb(v[i]);
            }
            if (v0.size()>n/2) {r=w-1;continue;}
            ll sm=0, o=0;
            for (int i = 0; i < v0.size(); i++) sm+=v0[i].fi;
            for (int i = 0; i < v2.size(); i++) sm+=v2[i].fi, o++;
            sort(v1.begin(),v1.end());
            reverse(v1.begin(),v1.end());
            for (int i = 0; i < v1.size(); i++)
            {
                if (o<n/2+1) o++, sm+=w; else sm+=v1[i].fi;
            }
            if (sm<=k) l=w; else r=w-1;
        }
        cout << l << "\n";
    }
    return 0;
}