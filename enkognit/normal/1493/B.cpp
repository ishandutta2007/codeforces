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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj, a[100001], rev[10];

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

void solve()
{
    ll h, m;
    string s;
    rev[0]=0;
    rev[1]=1;
    rev[2]=5;
    rev[5]=2;
    rev[8]=8;
    cin >> h >> m;
    cin >> s;
    ll m1=s.back()-'0'+(s[s.size()-2]-'0')*10;
    ll h1=s[s.size()-4]-'0'+(s[s.size()-5]-'0')*10;
    string d;
    for (int i = h1; i < h && d.size()==0; i++)
    {
        ll o=i;
        bool tt=1;
        while (o)
        {
            if (o%10!=1 && o%10!=2 && o%10!=0 && o%10!=5 && o%10!=8)
                tt=0;
            o/=10;
        }
        if (tt)
        for (int j = (i==h1)*m1; j < m; j++)
        {
            o=j;
            bool tt=1;
            while (o)
            {
                if (o%10!=1 && o%10!=2 && o%10!=0 && o%10!=5 && o%10!=8)
                    tt=0;
                o/=10;
            }
            if (tt)
            {
                if (rev[j%10]*10+rev[j/10]<h && rev[i%10]*10+rev[i/10]<m)
                {
                    d+=i/10+'0';
                    d+=i%10+'0';
                    d+=':';
                    d+=j/10+'0';
                    d+=j%10+'0';
                    break;
                }
            }
        }
    }

    if (d.size())
    {
        cout << d << "\n";
        return;
    }


    for (int i = 0; i < h && d.size()==0; i++)
    {
        ll o=i;
        bool tt=1;
        while (o)
        {
            if (o%10!=1 && o%10!=2 && o%10!=0 && o%10!=5 && o%10!=8)
                tt=0;
            o/=10;
        }
        if (tt)
        for (int j = 0; j < m; j++)
        {
            o=j;
            bool tt=1;
            while (o)
            {
                if (o%10!=1 && o%10!=2 && o%10!=0 && o%10!=5 && o%10!=8)
                    tt=0;
                o/=10;
            }
            if (tt)
            {
                if (rev[j%10]*10+rev[j/10]<h && rev[i%10]*10+rev[i/10]<m)
                {
                    d+=i/10+'0';
                    d+=i%10+'0';
                    d+=':';
                    d+=j/10+'0';
                    d+=j%10+'0';
                    break;
                }
            }
        }
    }
    cout << d << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
4 2
30 40 50 60
30 40
50 60

4 4
25 25 30 50
10 40
20 30
70 100
50 50
*/