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

ll n, m, W, l, r, ans, k, mn, mx;
ll t[100001], kol[100001];
string s;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    ll ans=0, w=0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        t[x]++;
        mx=max(mx,t[x]);
        if (t[x]>1)
        {
            kol[t[x]-1]--,kol[t[x]]++;
            //cout << mn << " " << kol[mn] << "\n";
            if (mn==t[x]-1 && kol[t[x]-1]==0) mn=t[x];
        }else
        {
            mn=1;
            kol[1]++;
            w++;
        }
        if ((mx==mn && mn==1) || w==1 || (kol[mx]+kol[mn]==w && ((mx-mn<2 && kol[mx]==1) || (mn==1 && kol[mn]==1)))) ans=i;
        //cout << mx << " " << mn << "\n";
        //cout << kol[mx] << "-" << kol[mn] << " " << w << "\n";
    }
    cout << ans+1;
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