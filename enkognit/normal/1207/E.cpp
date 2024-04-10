#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0;

pll a[400001];
map<ll,bool> tt;
string s;

ll fact(ll h)
{
    if (h==1) return 1; else return (h*fact(h-1))%MOD;
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    vector <ll> v;
    ll l1=0, r1=0;
    for (int i = 0; i < 100; i++) {v.pb(i);l1^=i;}
    tt[0]=1;
    ll p=99;
    while (v.size()<200)
    {
        p++;
        bool t=1;
        for (int i = 0; i < 100; i++)
        {
            if (tt[p^v[i]]) {t=0;break;}
        }
        if (t)
        {
            for (int i = 0; i < 100; i++)
            {
                tt[p^v[i]]=1;
            }
            v.pb(p);
            r1^=p;
        }
    }
    //cout << v.size()/2 << "\n";
    cout << "? ";
    for (int i = 0; i < v.size()/2-1; i++) cout << v[i] << " ";
    cout << v[v.size()/2-1] << "\n";
    fflush(stdout);
    ll o;
    cin >> o;
    cout << "? ";
    for (int i = v.size()/2; i < v.size()-1; i++) cout << v[i] << " ";
    cout << v[v.size()-1] << "\n";
    fflush(stdout);
    ll w;
    cin >> w;
    o^=w;
    //cout << o << "\n";
    for (int i = 0; i < v.size()/2; i++)
        for (int j = v.size()/2; j < v.size(); j++)
        {
            if ((v[i]^v[j])==o) {cout << "! " << (w^v[j]) << "\n";exit(0);}
        }

    //while (1) l++;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/