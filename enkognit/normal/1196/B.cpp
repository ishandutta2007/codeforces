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

using namespace std;

const ll MOD = 998244353;

ll n, m, k, a[200001], q, p, ans, l, r, i, j, x, y;

ll func(ll p,ll r,ll l)
{
    if (r+p<=l) return r+p; else
    return (p-(l-r))/2+l;
}

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
        cin >> n >> k;
        ll m=0, l=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]%=10;
            l+=a[i];
        }
        ll p=0;
        if (k==1)
        {
            if (l%2) cout << "YES\n" << n << "\n"; else cout << "NO\n";
            continue;
        }
        vector <ll> v={};
        //bool tt=0;
        for (int i = 0; i < n; i++)
        {
            p=a[i];
            l-=a[i];
            if (p%2)
            {
                m++;
                v.pb(i+1);
                if (m==k-1 && i+1!=n)
                {
                    if (l%2)
                    {
                        m++;
                        cout << "YES\n";
                        v.pb(n);
                        for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
                        cout << "\n";
                        //tt=1;
                    }
                    break;
                }
                p=0;
            }
        }
        if (m<k) cout << "NO\n";
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