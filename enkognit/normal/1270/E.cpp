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

ll l, r, n, m, k, x, y, w, h, T, a[1000001], dp[1000001][2];
bool tt[1000001], ttt;
vector <pll> c[100001];



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

vector <pll> v;
vector <pll> yyy;
vector <pair<ld,pll> > vv;

ld rast(int i,int j)
{
    return sqrt(sqr(v[i].fi-v[j].fi)+sqr(v[i].se-v[j].se));
}

struct dsu
{
    ll d[1001];

    void make_set(int h)
    {
        d[h]=h;
    }

    int find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x!=y) d[x]=y;
    }
};

vector<vector<pll> > p;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    v.pb(mp(x,y));
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    while (1)
    {
        ll a[4];
        a[0]=0;a[1]=0;a[2]=0;a[3]=0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].fi%2==0)
            {
                if (v[i].se%2==0) a[0]++;else a[1]++;
            }else
            if (v[i].se%2==0) a[2]++;else a[3]++;
        }
        if (a[0]==n || a[1]==n || a[2]==n || a[3]==n)
        {
            for (int i = 1; i < v.size(); i++) v[i].fi=(v[i].fi-abs(v[i].fi%2))/2,v[i].se=(v[i].se-abs(v[i].se%2))/2;continue;
        }
        vector<ll> ans;
        if (a[0]+a[3]==n)
        {
            for (int i = 1; i < v.size(); i++) if (v[i].fi%2 && v[i].se%2) ans.pb(i);
        }else
        if (a[1]+a[2]==n)
        {
            for (int i = 1; i < v.size(); i++) if (v[i].fi%2 && v[i].se%2==0) ans.pb(i);
        }else
        {
            for (int i = 1; i < v.size(); i++) if ((v[i].fi+v[i].se)%2==0) ans.pb(i);
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        exit(0);
    }
    //cout << 1;
    //cout << p.size() << "\n";
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