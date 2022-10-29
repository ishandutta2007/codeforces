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

ll n, m, k, sz;
bool tt[30][30];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h;
        h*=h;
        r/=2;
    }
    return l;
}

string s;

void dfs(int h)
{
    for (int i = k-1; i > -1; i--)
        if (tt[h][i])
        {
            tt[h][i]=0;
            dfs(i);
        }
    s+=(h+'a');
}

void solve()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            tt[i][j]=1;
    string s1, s2;
    if (k%2)
    {
        dfs(0);
        s1=s;
    }else
    {
        //for (int i = 1; i < k-1; i++)
        //    tt[i][i]=0;
        dfs(0);
        s1=s;
    }
    //cout << s1 << " " << s2 << "\n";
    string s="";
    bool t=0;
    while (n-(int)s.size()>(int)s1.size()-((int)s.size()>0))
    {
        if (s.size()) s.pop_back();
        s+=s1;
    }
    if (s.size()>0) s.pop_back();
    {
        ll i=0;
        while (s.size()<n) s+=s1[i], i++;
    }
    cout << s << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/