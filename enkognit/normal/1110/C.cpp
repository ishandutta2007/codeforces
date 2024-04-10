#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k, i, j, l, r, ans, a[200001];
ll b[100001];
short t[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        ll b=a;
        ll z=0;
        bool tt=0;
        while (a)
        {
            if (a%2==0) tt=1;
            a/=2;
            z++;
        }
        if (tt)
        {
            ll ans=0;
            for (ll j = 0; j < z; j++) ans=ans*2+1;
            cout << ans << "\n";
        } else
        {
            ll r=0;
            for (ll j = 1; j <= sqrt(b); j++)
                if (b%j==0)
            {r=max(r,j);if (j!=1)r=max(r,b/j);}

            cout << r << "\n";
        }
    }
    return 0;
}