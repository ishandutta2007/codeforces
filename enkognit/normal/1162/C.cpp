#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, x, h, y, ans, k, z;
ll t[200001];
string s, d;
vector <ll> v[200001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        t[x]++;
        v[x].pb(i+1);
    }
    for (int i = 1; i <= n; i++)
    {
        ll o=ans;
        if (t[i]==0) ans++;
        if (i<n)
        {
            if (t[i]==0) ans++;else
            if (t[i]>0 && t[i+1]==0) ans++;else
            if (t[i]>0 && t[i+1]>0 && v[i][0]>v[i+1][v[i+1].size()-1]) ans++;
        }
        if (i>1)
        {
            if (t[i]==0) ans++;else
            if (t[i]>0 && t[i-1]==0) ans++; else
            if (t[i]>0 && t[i-1]>0 && v[i][0]>v[i-1][v[i-1].size()-1]) ans++;
        }
        //cout << i << " " << ans-o << "\n";
    }
    cout << ans;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/