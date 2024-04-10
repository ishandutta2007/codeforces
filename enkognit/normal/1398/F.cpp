#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, kl1, kl2, f, nxt0[1000005], nxt1[1000005];

vector<ll> p0[1000005], p1[1000005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    nxt0[n+1]=n+1;
    nxt1[n+1]=n+1;
    for (int i = n; i > 0; i--)
    {
        nxt0[i]=nxt0[i+1];
        nxt1[i]=nxt1[i+1];
        if (s[i]=='1') nxt1[i]=i;
        if (s[i]=='0') nxt0[i]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i]!='0' && (i==1 || s[i-1]=='0'))
        {
            for (int j = nxt0[i]-i; j > 0; j--)
            {
                p1[j].pb(i);
            }
        }else
        if (s[i]!='1' && (i==1 || s[i-1]=='1'))
        {
            for (int j = nxt1[i]-i; j > 0; j--)
            {
                p0[j].pb(i);
            }
        }
    }

    //cout << "----\n";

    for (int i = 1; i <= n; i++)
    {
        ll l=0, r=0, p=1, an=0;
        //cout << i << "\n";
        while (p<=n)
        {
            while (l<p0[i].size() && p0[i][l]<=p) l++;
            while (r<p1[i].size() && p1[i][r]<=p) r++;
            //cout << " " << p << " " << (l<p0[i].size()?p0[i][l]:-1) << " " << (r<p1[i].size()?p1[i][r]:-1) << "\n";
            if (max(nxt0[p],nxt1[p])-p>=i)
            {
                //cout << "-\n";
                p+=i;
                an++;
            }else
            {
                if (l==p0[i].size() && r==p1[i].size())
                {
                    break;
                }
                if (l==p0[i].size() || (r<p1[i].size() && l<p0[i].size() && p1[i][r]<p0[i][l]))
                    p=p1[i][r]; else p=p0[i][l];
            }
        }
        cout << an << " ";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
01000000
10100000
31100000
00020000
00000000
00000000
00000000
00000000

01100000
10100000
01100000
00100000
00100000
00100000
13112101
00011111
*/