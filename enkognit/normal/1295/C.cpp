#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double

using namespace std;

ll md1=1e9+9, md2=998244357, p1=31, p2=127;

ll n, m, k, i, j, x;
string s, d;
vector<ll> v[101];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cin >> d;
        for (int i = 0; i < 50; i++) v[i].clear();
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i]-'a'].pb(i);
        }
        ll nw=-1, ans=0;
        bool tt=0;
        for (int i = 0; i < d.size(); i++)
        {
            if (v[d[i]-'a'].size()==0) {tt=1;break;}
            ll l=0, r=v[d[i]-'a'].size()-1;
            while (l<r)
            {
                int w=(l+r)/2;
                if (v[d[i]-'a'][w]<=nw) l=w+1; else r=w;
            }
            if (v[d[i]-'a'][l]<=nw) ans++, nw=v[d[i]-'a'][0]; else
                nw=v[d[i]-'a'][l];
        }
        if (tt) cout << -1 << "\n"; else cout << ans+1 << "\n";
    }
    return 0;
}
/*
 ll x;
        cin >> n >> x;
        cin >> s;
        ll kl=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i==0) a[i]=0; else a[i]=a[i-1];
            if (s[i]=='1') a[i]--; else a[i]++;
            if (a[i]==x) kl++;
        }
        if (a[n-1]==0 && kl>0) {cout << "-1\n";continue;}
        ll ans=0;
        if (x==0) ans++;
        if (a[n-1]>0)
        for (int i = 0; i < n; i++)
            if ((x-a[i])%a[n-1]==0 && (x-a[i])/a[n-1]>=0) ans++;
        cout << ans << "\n";
*/