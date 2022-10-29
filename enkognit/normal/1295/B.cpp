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

ll n, m, k, i, j, a[1000001], b[1000001];
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
        ll n, x;
        cin >> n >> x;
        cin >> s;
        s=' '+s;
        ll kl=0;
        if (x==0) kl++;
        for (int i = 0; i <= n; i++) a[i]=0;
        for (int i = 1; i <= n; i++)
        {
            a[i]=a[i-1];
            if (s[i]=='1') a[i]--; else a[i]++;
            if (a[i]==x) kl++;
        }
        if (a[n]==0 && kl>0) {cout << "-1\n";continue;}
        ll ans=0;
        if (a[n]!=0)
        for (int i = 0; i < n; i++)
        {
            //cout << i << " : " << abs((x-a[i]))%abs(a[n]) << " " << (x-a[i])/a[n] << "\n";
            if (abs((x-a[i]))%abs(a[n])==0 && (x-a[i])/a[n]>=0) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
*/