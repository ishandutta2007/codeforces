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
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y, kol=0, a[1000001];
vector <ll> c[300001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll p=0;
        for (int i = 0; i < n*4; i++) {cin >> a[i];}
        sort(a,a+n*4);
        vector <ll> v;
        for (int i = 1; i < n*4; i++)
        {
            if (a[i]==a[i-1]) {v.pb(a[i]);p++;i++;}
        }
        if (v.size()!=n*2) {cout << "NO\n";continue;}
        ll o=v[0]*v[v.size()-1];
        bool tt=1;
        //cout << o << "\n";
        ll l=1, r=v.size()-2;
        while (l<r)
        {
            if (v[l]*v[r]!=o) {tt=0;}
            l++,r--;
        }
        if (tt) cout << "YES\n"; else cout << "NO\n";
    }
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