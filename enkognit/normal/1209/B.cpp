#include <bits/stdc++.h>
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

ll n, m, i, n1, p, n2, k, j, y, kol=1,  a[200001], b[200001];
string s, d;
vector <ll> v, c[300001];
ll tt[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    ll nw=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='1') nw++;
        cin >> a[i] >> b[i];
        ll p=(s[i]=='1'), z=b[i];
        while (z<=1000)
        {
            if (p) tt[z]--, p--; else tt[z]++,p++;
            z+=a[i];
        }
    }
    ll ans=nw;
    for (int i = 1; i <= 1000; i++)
    {
        nw+=tt[i];
        ans=max(ans, nw);
    }
    cout << ans;
    return 0;
}