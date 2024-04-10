#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=998244353;

ll n, m, k, T, mx, X, q, a[200005];

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    multiset<ll> s;
    ll sm=0, j=0, o=0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i]>=0)
        {
            j++;
            sm+=a[i];
        }else
        {
            s.insert(a[i]);
            o+=a[i];
            while (sm+o<0)
            {
                o-=(*s.begin());
                s.erase(s.begin());
            }
        }
        //cout << sm << " " << o << " " << s.size() << "\n";
    }
    cout << j+s.size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6
1 2 3 4 5 6
1 2
3 1
3 4
3 5
3 6
5
1 2 5
1 4 3
1 6 6
2 1 3
1 2 5
*/


/*
ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}
*/