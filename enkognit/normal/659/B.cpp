#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, s, x, ans, y, ln, w, h, T, a[1000001], dp[1000001];
bool tt[1000001], ttt;
vector <pair<ll,string> > v[20001];

template<typename BRUH>
inline BRUH sqr(BRUH x)
{
    return x*x;
}

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return 1;
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // LOCAL
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        string s;
        cin >> s >> x >> y;
        v[x].pb(mp(y,s));
    }
    for (int i = 1 ;i <= m ; i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        if (v[i].size()>2 && v[i][1].fi==v[i][2].fi) cout << "?\n"; else
        cout << v[i][0].se << " " << v[i][1].se << "\n";
    }
    return 0;
}
/*
3 3 0
1 a
2 b
3 a
4 b
2 a
*/