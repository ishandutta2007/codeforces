#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, y;
bool b[100001][31];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

ll rec(int j,vector<int> v)
{
    if (j==-1) return 0;
    vector<int>  v0, v1;
    for (int i = 0; i < v.size(); i++)
        if (b[v[i]][j]==0) v0.pb(v[i]); else v1.pb(v[i]);
    if (v0.size()==0 || v1.size()==0) return rec(j-1,(v1.size()?v1:v0)); else
    {
        return ((1<<j)+min(rec(j-1,v0),rec(j-1,v1)));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.pb(i);
        ll x;
        cin >> x;
        ll j=0;
        while (x)
        {
            b[i][j]=x%2;
            x/=2;
            j++;
        }
    }
    cout << rec(30,v);
    return 0;
}
/*
4
0 5 1
1 7 2
4 4 1
7 15 1
*/