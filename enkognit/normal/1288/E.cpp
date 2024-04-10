#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit
#define sqr(a) ((a)*(a))

using namespace std;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, i, j, d[10000001], b[10000001], kl[300005];
pll ans[300005];ll a[300005];
vector<ll> tt[300003], v[300002];
vector<pair<pll,ll> > vv;
bool tl[1000001];

bool comp(pair<pll,ll> x,pair<pll,ll> y)
{
    return x.fi.se<y.fi.se || x.fi.se==y.fi.se && x.fi.fi<y.fi.fi;
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void update(int h,int l,int r,int x)
{
    if (l==r) {d[h]=1;return;}
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) ans[i].fi=i, ans[i].se=i;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        v[a[i]].pb(i);
        ans[a[i]].fi=1;
    }
    for (int i = 1; i <= n; i++) v[i].pb(m+1);
    ll k=0;
    for (int i = 1; i <= n; i++)
    {
        //k++;
        tt[v[i][0]].pb(i);
        for (int j = 0; j < v[i].size()-1; j++)
        {
            k++;
            vv.pb(mp(mp(v[i][j]+1,v[i][j+1]-1),k));
        }
    }
    //cout << 1;
    for (int i = 1; i <= m+1; i++)
    {
        for (int j = 0; j < tt[i].size(); j++) ans[tt[i][j]].se=max(get(1,1,n,tt[i][j]+1,n)+tt[i][j],ans[tt[i][j]].se),
            update(1,1,n,tt[i][j]);
    }
    sort(vv.begin(),vv.end());
    ll lr=0, p=sqrt(m);
    tl[0]=1;
    for (int i = 0; i < vv.size(); i++)
    {
        if (i && vv[i-1].fi.fi/p<vv[i].fi.fi/p)
        {
            sort(vv.begin()+lr,vv.begin()+i,comp);
            lr=i;
            tl[i]=1;
        }
    }
    sort(vv.begin()+lr,vv.end(),comp);
    ll l=0, r=0, kol=0;
    for (int i = 0; i < vv.size(); i++)
    {
        if (tl[i])
        {
            l=vv[i].fi.fi, r=vv[i].fi.se, kol=0;
            for (int i = 1; i <= n; i++) kl[i]=0;
            for (int i = l; i <= r; i++) {if (kl[a[i]]==0) kol++;kl[a[i]]++;}
            //cout << l << " - " << r << " " << kol << " " << vv "\n";
            b[vv[i].se]=kol;
        }else
        {
            while (r<vv[i].fi.se)
            {
                r++;
                if (kl[a[r]]==0) kol++;
                kl[a[r]]++;
            }
            while (l>vv[i].fi.fi)
            {
                l--;
                if (kl[a[l]]==0) kol++;
                kl[a[l]]++;
            }
            while(l<vv[i].fi.fi)
            {
                kl[a[l]]--;
                if (kl[a[l]]==0) kol--;
                l++;
            }
            while(r>vv[i].fi.se)
            {
                kl[a[r]]--;
                if (kl[a[r]]==0) kol--;
                r--;
            }
            b[vv[i].se]=kol;
        }
    }
    k=0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < v[i].size()-1; j++)
        {
            k++;
            //cout << v[i][j] << " " << v[i][j+1] << " " << b[k] << "\n";
            ans[i].se=max(ans[i].se,b[k]+1);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i].fi << " " << ans[i].se << "\n";
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2
*/