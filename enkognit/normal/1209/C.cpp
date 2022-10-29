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
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) a[i]=0;
        ll mn=1e18, mx=0, pmx=0, pmn=0;
        cin >> s;
        s=' '+s;
        for (int i = 1; i <= n; i++)
        {
            if (s[i]-48>=mx) mx=s[i]-48, pmx=i;
            if (s[i]-48<mn) mn=s[i]-48, pmn=i;
        }
        string g=s;
        sort(g.begin()+1,g.end());
        bool tp=0;
        if (pmn-1>pmx) {cout << "-\n";continue;}
        for (int i = 2; i < pmn; i++) if (s[i-1]>s[i]) tp=1;
        for (int i = pmx+2; i <= n; i++) if (s[i-1]>s[i]) tp=1;
        if (tp) {cout << "-\n";continue;}
        ll l=1;
        for (int i = pmn; i <= n; i++)
        {
            if (!a[i])
            {
                if (s[i]==g[l]) l++, a[i]=1;
            }
        }
        for (int i = 1; i <= pmx; i++)
        {
            if (!a[i])
            {
                if (s[i]==g[l]) l++, a[i]=2;
            }
        }
        if (l<g.size()) cout << "-"; else
            for (int i = 1; i <= n; i++) cout << a[i];
        cout << "\n";
    }
    return 0;
}