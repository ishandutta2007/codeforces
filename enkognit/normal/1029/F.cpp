#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, b, r, a[100001];
pll ans;

bool IsPrime(ll h,ll o)
{
    bool tt=1;
    for (int i = 2; i <= sqrt(h); i++) if (h%i==0) {tt=0;break;}
    return tt;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    if (n>m) swap(n,m);
    ll ans=1e18;
    for (ll i = 1; i <= sqrt(n+m); i++)
        if ((n+m)%i==0)
        {
            bool tt=0;
            for (ll j = i; j > 0; j--) if ((n%j==0 && n/j<=(n+m)/i) || (m%j==0 && m/j<=(n+m)/i)) {tt=1;break;}
            if (tt)
            {
                //cout << i << " " << (n+m)/i << "\n";
                ans=min(ans,i*2+(n+m)/i*2);
            }
        }
        cout << ans;
    return 0;
}