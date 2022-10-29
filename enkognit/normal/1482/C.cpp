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

ll n, T, m, ans=0;
ll sz=1;
int bn[1000005][20];
bool tt[1000005];
int mn[1000005];
int d[1000005][26];
int gog[1000005][26];
int lnk[1000005];
int pp[1000005];
int mx[1000005];
int hh[1000005];
int ch[1000005];
int lf[1000005];
int in[1000005];
int out[1000005];
vector<int> c[2000005];

int go(int h,int c);

int link(int h)
{
    if (lnk[h]) return lnk[h]; else
    if (hh[h]<2) return lnk[h]=1; else
    return lnk[h]=go(link(pp[h]), ch[h]);
}

int go(int h,int c)
{
    if (gog[h][c]) return gog[h][c]; else
    if (d[h][c]) return gog[h][c]=d[h][c]; else
    if (h==1) return 1; else return gog[h][c]=go(link(h), c);
}

int get(int h)
{
    if (mx[h]!=-1) return mx[h]; else
    if (h==1) return mx[h]=0; else
    {
        //if (h==20) cout << "   " << h << " " << link(h) << " " << tt[link(h)] << "\n";
        return mx[h]=get(link(h));
    }
}

struct fenwick{
    int f[2100005];

    void upd(int h,int k)
    {
        for (int i = h; i <= 2e6+1e5; i+=(i&-i)) f[i]+=k;
    }

    ll get(int h)
    {
        ll ans=0;
        for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
        return ans;
    }
} f;

void add(int h,int k,string &s)
{
    while (k<=s.size())
    {
        //if (k%1000==0) cout << h << " " << k << "\n";
        if (k==s.size())
        {
            mx[h]=k;
            tt[h]=1;
            return;
        }
        if (d[h][s[k]-'a']==0)
        {
            sz++;
            //cout << h << " " << sz << " " << s[k] << "\n";
            hh[sz]=hh[h]+1;
            d[h][s[k]-'a']=sz;
            pp[sz]=h;
            ch[sz]=s[k]-'a';
            mx[sz]=-1;
        }
        h=d[h][s[k]-'a'];
        k++;
    }
}

ll up(int h,int k)
{
    if (hh[h]<k) return h;
    for (int i = 19; i > -1; i--)
        if (hh[bn[h][i]]>=k) h=bn[h][i];

    //cout << "-- "  << h << " " << hh[h] << " "<< bn[h][0] << " " << k << " --";

    return bn[h][0];
}

void dfs(int h,int p=1)
{
    in[h]=++T;

    //cout << h << " ";

    bn[h][0]=p;

    for (int i = 1; i < 20; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];

    for (int i = 0; i < c[h].size(); i++)
    {
        dfs(c[h][i], h);
    }
    out[h]=++T;
    //cout << h << " ";
}

void get_answer(string &s)
{
    ll h=1;

    vector<ll> zp;

    for (int i = 0; i < s.size(); i++)
    {
        h=go(h, s[i]-'a');

        ll o=get(h);

        if (i+1==s.size()) o=get(link(h));


        if (o>0)
        {
            ll z=up(h, o);
            //cout << i+1 << " " << h << " " << o << " " << z << "\n";
            lf[i+1]=hh[h]-o;
            zp.pb(out[z]);
            f.upd(out[z], 1);
        }else lf[i+1]=1e9;

    }

    ll mn=1e18, H=h;

    for (int i = s.size(); i > 0; i--)
    {
        if (mn<i)
        {
            ll z=up(h, i-mn+1);
            //cout << " - " << i << " " << z << " " << i-mn+1 << "\n";
            zp.pb(out[z]);
            f.upd(out[z], 1);
        }
        h=pp[h];
        if (mn>lf[i]) mn=lf[i]; else lf[i]=1e9;
    }

    h=H;

    for (int i = s.size(); i > 0; i--)
    {
        if (lf[i]<1e8)
        {
            ll z=up(h, hh[h]-lf[i]+1);
            //cout << i << " " << h << " " << z << " " << hh[h]-lf[i]+1 << "\n";

            if (f.get(out[z])-f.get(in[z])==0)
            {
                ans++;
            }
            zp.pb(out[z]);
            f.upd(out[z], 1);
        }
        h=pp[h];
    }

    for (int i = 0; i < zp.size(); i++)
        f.upd(zp[i], -1);
}

void solve()
{
    cin >> n;
    mx[1]=-1;
    vector<string> v;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        //for (int j = 0; j < 1e6; j++) s+='a';
        v.pb(s);
        add(1,0,s);
    }

    //cout << "---\n";

    for (int i = 2; i <= sz; i++)
        c[link(i)].pb(i);

    dfs(1);
    //cout << T << "\n";
    //cout << "\n";
    //cout << "---\n";
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i] << "\n";
        get_answer(v[i]);
    }

    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/