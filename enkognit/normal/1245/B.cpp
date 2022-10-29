#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, a[1000001];
pll b[100001];
string s, d;
vector <ll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        cin >> a[0] >> a[1] >> a[2];
        string s;
        ll ans=0;
        cin >> s;
        string d="";
        for (int i = 0; i < n; i++)
        {
            d+='-';
            if (s[i]=='R' && a[1]>0) a[1]--, d[i]='P', ans++;else
            if (s[i]=='S' && a[0]>0) a[0]--, d[i]='R', ans++;else
            if (s[i]=='P' && a[2]>0) a[2]--, d[i]='S', ans++;
        }
        if (ans<(n+1)/2) cout << "NO\n"; else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                if (d[i]=='-')
                {
                    if (a[0]>0) d[i]='R', a[0]--; else
                    if (a[2]>0) d[i]='S', a[2]--; else
                    if (a[1]>0) d[i]='P', a[1]--;
                }
                cout << d[i];
            }
            cout << "\n";
        }
    }
    return 0;
}