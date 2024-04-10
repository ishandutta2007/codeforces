#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
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

ll n, T, m, ans=0, a[100001];
string s, d1, d2;

void solve()
{
    cin >> n;
    cin >> s;
    ll o1=0, o2=0, kl0=0, kl1=0;
    d1="";
    d2="";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='0') kl0++; else kl1++;
    }
    if (kl0%2 || s[0]=='0' || s.back()=='0')
    {
        cout << "NO\n";
        return;
    }
    ll u=kl1/2, q=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='0')
        {
            if (q%2==0) d1+=')'; else d1+='(';
            q++;
        }else
        {
            if (u>0) u--, d1+='('; else d1+=')';
        }
    }

    u=kl1/2, q=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='0')
        {
            if (q%2==1) d2+=')'; else d2+='(';
            q++;
        }else
        {
            if (u>0) u--, d2+='('; else d2+=')';
        }
    }
    cout << "YES\n";
    cout << d1 << "\n";
    cout << d2 << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/