#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = (1ll << 30) + 1;
//mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, T, kl = 0, m, ans, p, w, d1[2000001], d2[2000001], d[2000001];
pll hs[1000001];
vector<ll> c[100001];
vector<ll> v;
bool tt[1000001];
int tl[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i <= n; i++) d1[i] = 1, d2[i] = 0;
    ll l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        ll k = 1;
        if (i <= r) k = min(d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) {k++;}
        d1[i] = k;
        if (i + k - 1 > r)
            l = i - k + 1, r = i + k - 1;
    }
    //cout << d1[4] << "\n";

    l = 0, r = -1;
    for (int i = 0; i < n; ++i)
    {
        ll k = 0;
        if (i <= r) k = min(d[l + r - i + 1], r - i + 1);
        while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])  ++k;
        d[i] = k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }

    for (int i = 0; i < s.size() - 1; i++) d2[i] = d[i + 1];


    ll o = -1;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            o = i;
            break;
        }
    }
    if (o == -1) { cout << s << "\n";return; }
    ll ans = o * 2;
    l = o-1, r = o;
    for (int i = 0; i < n; i++)
    {
        if (i - d1[i] < o && i<s.size()/2)
        {
            //cout << i << " " << d1[i] << "\n";
            if (ans < (i - d1[i] + 1) * 2 + (d1[i] * 2 - 1))
            {
                ans = (i - d1[i] + 1) * 2 + (d1[i] * 2 - 1);
                //if (ans==9) cout << d1[i] << " " << i << "\n";
                l = i + d1[i] - 1;
                r = i - d1[i] + 1;
                //cout << ans << " " << l << " " << r << "\n";
            }
        }
        //cout << i << " " << d1[i] << " " << s.size()/2 << "\n";
        if (i + d1[i] >= s.size() - o && i >= s.size()/2)
        {
            //cout << i << " " << d1[i] << "\n";
            if (ans < (d1[i] * 2 - 1) + (s.size() - (i + d1[i] - 1) - 1) * 2)
            {
                ans = (d1[i] * 2 - 1) + (s.size() - (i + d1[i] - 1) - 1) * 2;
                l = (s.size() - (i + d1[i] - 1) - 1) - 1;
                r = s.size() - (i - d1[i] + 1);
                //cout << ans << " " << l << " " << r << "\n";
            }
        }

        if (d2[i] == 0) continue;

        //cout << i << " " << d2[i] << "\n";

        if (i - d2[i] + 1 <= o && i<s.size()/2)
        {
            if (ans < (i - d2[i] + 1) * 2 + (d2[i] * 2))
            {
                //cout << "-\n";
                ans = (i - d2[i] + 1) * 2 + (d2[i] * 2);
                l = i + d2[i];
                r = i - d2[i] + 1;
            }
        }

        if (i + d2[i] + 1 >= s.size() - o && i>=s.size()/2)
        {
            if (ans < (s.size() - (i + d2[i] + 1)) * 2 + (d2[i] * 2))
            {
                ans = (s.size() - (i + d2[i] + 1)) * 2 + (d2[i] * 2);
                l = (s.size() - (i + d2[i] + 1)) - 1;
                r = s.size() - (i - d2[i] + 1);
            }
        }
    }
    //cout << ans << " " << l << " " << r << "\n";
    for (int i = 0; i <= l; i++) cout << s[i];
    for (int i = s.size() - r; i < s.size(); i++) cout << s[i];
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}