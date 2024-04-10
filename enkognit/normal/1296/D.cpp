#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, y, aa[1000001];
vector<pll> c[200001];vector<ll> vv;
bool tt[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> n >> a >> b >> k;
    vector<ll> v;
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> aa[i];
        if (aa[i]%(a+b)==0) aa[i]=a+b; else aa[i]=aa[i]%(a+b);
        if (aa[i]<=a) ans++; else
            v.pb(aa[i]-a);
    }
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        ll p=v[i]/a+((v[i]%a)>0);
        if (p<=k) k-=p, ans++; else break;
    }
    cout << ans;
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/