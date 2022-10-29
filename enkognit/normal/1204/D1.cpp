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

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, sf[100001], pr[100001];
pll  d[1000001];
string s;

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    s=' '+s;
    ll n=s.size()-1;
    for (int i = 1; i <= n; i++) pr[i]=pr[i-1]+(s[i]=='0');
    for (int i = n; i > 0; i--) sf[i]=sf[i+1]+(s[i]=='1');
    vector <pll> v={};
    for (int i = 1; i <= n; i++)
    {
        ll mx=0, pos=0;
        for (int j = i; j <= n; j++)
        {
            if (pr[j]-pr[i-1]+sf[j]>=mx) mx=pr[j]-pr[i-1]+sf[j], pos=j;
        }
        if (pos>i) v.pb(mp(i,pos-1));
    }
    ll lst=1;
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i].fi << " " << v[i].se << "\n";
        for (int j = lst; j < v[i].fi; j++) s[j]='0';
        lst=v[i].se+1;
    }
    for (int j = lst; j <=n ;j++) s[j]='0';
    s.erase(0,1);
    cout << s;
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