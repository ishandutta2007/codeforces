#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, k, ans, b[200005];
ll a[500005];
string s, d;
vector <ll> v;
bool t[4000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    //ll x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans=n, p=1;

    for (int i = 0; i < n; i++)
    {
        if (a[i]==4) v.pb(1);else
        if (a[i]==8)
        {
            ll l=0, r=v.size();
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w]>1) l=w+1; else r=w;
            }
            if (v.size() && v[l]==1) v[l]++;
            //if (v[l]==6) ans-=6;
        }else
        if (a[i]==15)
        {
            ll l=0, r=v.size();
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w]>2) l=w+1; else r=w;
            }
            if (v.size() && v[l]==2) v[l]++;
            //if (v[l]==6) ans-=6;
        }else
        if (a[i]==16)
        {
            ll l=0, r=v.size();
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w]>3) l=w+1; else r=w;
            }
            if (v.size() && v[l]==3) v[l]++;
            //if (v[l]==6) ans-=6;
        }else
        if (a[i]==23)
        {
            ll l=0, r=v.size();
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w]>4) l=w+1; else r=w;
            }
            if (v.size() && v[l]==4) v[l]++;
            //if (v[l]==6) ans-=6;
        }else
        if (a[i]==42)
        {
            ll l=0, r=v.size();
            while (l<r)
            {
                ll w=(l+r)/2;
                if (v[w]>5) l=w+1; else r=w;
            }
            if (v.size() && v[l]==5) v[l]++;
            if (v.size() && v[l]==6) ans-=6;
        }
    }
    cout << ans;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/