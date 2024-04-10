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

ll n, k, l, m, r, i, j, x, y, ans, a[1000001];
pll b[200001];
bool tt[1000001];
string s;

vector <pll > v;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t=0;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        v.clear();
        ll mx=-1e18, p=-1e18, z=0;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].fi >> b[i].se;
            tt[i]=0;
            mx=max(b[i].fi,mx);
            if (p<b[i].fi-b[i].se) p=b[i].fi-b[i].se, z=b[i].fi;
        }
        if (p<=0 && m>mx) cout << "-1\n"; else
        if (mx>=m) cout << "1\n"; else
        {
            cout << max((m-mx),0ll)/p+1+(max((m-mx),0ll)%p>0) << "\n";
        }
    }

    return 0;
}