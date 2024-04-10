#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, t, j, sum, kol=0, a[1000001], d[1000001];
pll b[1000001];
string s;
vector <pll> v;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<string,ll> w;
        string s[100];
        for (int i = 0 ;i < n; i++)
        {
            cin >> s[i];
            w[s[i]]++;
        }
        ll ans=0;
        for (int i = 0; i < n; i++)
            if (w[s[i]]>1)
            {
                string d=s[i];
                for (int j = 0; j < 10; j++)
                {
                    d[0]=j+48;
                    if (w[d]==0) {w[d]++;ans++;break;}
                }
                w[s[i]]--;
                s[i]=d;
            }
        cout << ans << "\n";
        for (int i = 0 ;i < n;i++) cout << s[i] << "\n";
    }

    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/