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

ll n, dd, m, k, T, jj, pr[100005][26], pp[30];

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
    cin >> n >> k;
    string s;
    cin >> s;
    if (n%k)
    {
        cout << "-1\n";
        return;
    }
    s=' '+s;
    for (int i = 0; i < 26; i++) pp[i]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
            pr[i][j]=pr[i-1][j];
        pr[i][s[i]-'a']++;
    }
    bool tt=1;
    for (int i = 0; i < 26; i++)
        if (pr[n][i]%k) tt=0;
    if (tt)
    {
        s.erase(s.begin());
        cout << s << "\n";
        return;
    }
    ll p=-1;
    ll c=0;
    for (int i = n; i > 0 && p==-1; i--)
    {
        ll kl=0;
        for (int j = 0; j < 26; j++)
        {
            kl+=(k-pr[i-1][j]%k)%k;
        }
        for (int j = s[i]-'a'+1; j < 26; j++)
        {
            kl-=(k-pr[i-1][j]%k)%k;
            kl+=(k-(pr[i-1][j]+1)%k)%k;
            if (n-i>=kl && (n-i-kl)%k==0)
            {
                p=i;
                c=j;
                break;
            }
            kl+=(k-pr[i-1][j]%k)%k;
            kl-=(k-(pr[i-1][j]+1)%k)%k;
        }
    }
    if (p==-1)
    {
        cout << "-1\n";
        return;
    }
    //cout << p << " " << c << "\n";
    string d="";
    for (int i = 1; i < p; i++) d+=s[i];
    d+=c+'a';
    ll kl=0;
    for (int i = 0; i < 26; i++)
    {
        if (c==i)
        {
            pp[i]=(k-(pr[p-1][i]+1)%k)%k;
        }else
        {
            pp[i]=(k-pr[p-1][i]%k)%k;
        }
        kl+=pp[i];
        //cout << i << " " << pp[i] << "\n";
    }
    kl=n-p-kl;
    while (kl) d+='a', kl--;
    ll l=0;
    for (int i = p+1; i <= n; i++)
    {
        while (l<26 && pp[l]==0) l++;
        if (l==26)
        {
            break;
        }else
        {
            d+=(l+'a');
            pp[l]--;
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