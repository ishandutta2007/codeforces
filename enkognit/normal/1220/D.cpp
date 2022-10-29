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

const ll MOD = 1000000007;

ll n, k, l, m, r, i, j, x, y, ans, a[1000001];
vector <ll> v[1000], z;
string s;
bool tt[1000001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i]=x;
        ll z=x, p=0;
        while (z%2==0)
        {
            z/=2, p++;
        }
        v[p].pb(i);
        mx=max(p,mx);
    }
    ll p=v[0].size(), o=0;
    for (int i = 0; i <= mx; i++)
        if (v[i].size()>p)
        {
            p=v[i].size();
            o=i;
        }
    //cout << o << "\n";
    for (int i = 0; i < v[o].size(); i++) tt[v[o][i]]=1;
    cout << n-p << "\n";
    for (int i = 0; i < n; i++) if (!tt[i]) cout << a[i] << " ";
    return 0;
}