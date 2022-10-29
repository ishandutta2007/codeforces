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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, kl, m, k, i, j, h;
string s;
bool tt[1000001];
ll a[1000001], b[1000001];

void solve()
{
    cin >> n;
    cin >> s;
    vector<ll> v;
    for (int i = 1 ;i <= n; i++)a[i]=0,b[i]=0;
    v.pb(1);
    ll kl=1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='<') v.pb(i+2), kl++;
    }
    ll j=n-kl;
    for (int i = 0; i < v.size(); i++)
    {
        j++;
        a[v[i]]=j;
    }
    vector<ll> p;
    ll u=n;
    for (int i = 0; i < v.size(); i++)
    {
        if (i>0 && v[i]!=v[i-1]+1)
        {
            for (int j = 0; j < p.size(); j++)
            {
                b[p[j]]=u-p.size()+j+1;
            }
            u-=p.size();
            p.clear();
        }
        p.pb(v[i]);
    }
    for (int j = 0; j < p.size(); j++)
    {
        b[p[j]]=u-p.size()+j+1;
    }
    u-=p.size();
    p.clear();

    ll o=n-kl;
    for (int i = 1; i <= n; i++)
        if (a[i]==0) a[i]=o, b[i]=o, o--;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}
/*
*/