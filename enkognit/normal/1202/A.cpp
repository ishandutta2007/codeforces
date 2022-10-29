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

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y, a[500001];
vector <ll> c[300001];
vector <ll> v;
ll d[1000001];
bool t[1000001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        string x, y;
        cin >> y >> x;
        ll l=0, r=0;
        for (int i = x.size()-1; i > -1; i--)
            if (x[i]=='1') {l=i;break;}
        l=x.size()-l;
        for (int i = y.size()-1; i > -1; i--)
        {
            if (y[i]=='1' && y.size()-i>=l)
            {
                r=i;break;
            }
        }
        r=y.size()-r;
        cout << r-l << "\n";
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