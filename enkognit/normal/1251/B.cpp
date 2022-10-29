#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[500001], d[1000001];
string s;
vector <ll> v;
bool tt[1000001], q[1000001];

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll k1=0, k0=0;
        vector <ll> v;
        for (int it = 0; it < n; it++)
        {
            cin >> s;
            v.pb(s.size());
            for (int i = 0; i < s.size(); i++) if (s[i]=='1') k1++; else k0++;
        }
        sort(v.begin(),v.end());
        ll ans=0;
        bool t=0;
        //cout << k1 << " " << k0 << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i]%2)
            {
                if (k1%2 && k0%2==0) k1--; else
                if (k1%2==0 && k0%2) k0--; else
                if (k1>k0) k1--; else k0--;
            }
            for (int j = 0; j < v[i]/2; j++)
            {
                if (k0>k1) k0-=2; else k1-=2;
                if (k0<0 || k1<0) t=1;
            }
            if (t) break; ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}