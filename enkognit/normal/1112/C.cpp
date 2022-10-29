#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, a[1000001], s, t[1000001], tt[1000001];
pll b[1000001];
vector <ll> v;

template<typename T>
T sqr(T x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m >> k >> n >> s;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < s; i++)
    {
        ll x;
        cin >> x;
        t[x]++;
        tt[x]++;
    }
    ll kol=s;
    ll p=m-(n-1)*k;
    for (int i = 0; i < p; i++)
    {
        t[a[i]]--;
        if (t[a[i]]>=0) kol--;
    }
    if (kol==0)
    {
        ll o=k-s;
        for (int i = 0; i < p; i++)
        {
            if (tt[a[i]]) tt[a[i]]--; else
            if (o==0)v.pb(i+1); else o--;
        }
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        exit(0);
    }
    //cout << p << "\n";
    for (int i = p; i < m; i++)
    {
        t[a[i-p]]++;
        if (t[a[i-p]]>0) kol++;
        t[a[i]]--;
        if (t[a[i]]>=0) kol--;
        //cout << i << " " << kol << " " << t[2] << "\n";
        if (kol==0 && (i-p+1)%k==0)
        {
            ll o=k-s;
            for (int j = i-p+1; j <= i; j++)
            {
                if (tt[a[j]]) tt[a[j]]--; else
                if (o==0)v.pb(j+1); else o--;
            }
            cout << v.size() << "\n";
            for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
            exit(0);
        }
    }
    cout << -1;
    return 0;
}