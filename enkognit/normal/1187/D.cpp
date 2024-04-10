#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define leng length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, ans, q, l, r, i, j, a[1000005], b[1000005];
bool tt[1000001];
vector <pll> v1, v0;
ll d[2000005], z[2000005];

void build(ll h,ll l,ll r)
{
    z[h]=r-l+1;
    if (l==r) {d[h]=a[l];return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll geti(ll h,ll l,ll r,ll x)
{
    if (l==r) return l;
    ll w=(l+r)/2;
    if (z[h*2]>=x) return geti(h*2,l,w,x); else return geti(h*2+1,w+1,r,x-z[h*2]);
}

ll get(ll h,ll l,ll r,ll x, ll y)
{
    if (x>y) return 0;
    if (l==x && y==r)
    {
        return d[h];
    }
    ll w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void update(ll h,ll l,ll r,ll x)
{
    z[h]--;
    if (l==r)
    {
        d[h]=0;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w)update(h*2,l,w,x);else
    update(h*2+1,w+1,r,x);
    d[h]=max(d[h*2],d[h*2+1]);
}

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> q;
  while(q--)
  {
      vector <ll> v1={}, v2={};
      cin >> n;
      vector <ll> p[n+5];
      for (int i = 1; i <= n; i++) {cin >> a[i];v1.pb(a[i]);p[a[i]].pb(i);}
      build(1,1,n);
      for (int i = 1; i <= n; i++) {cin >> b[i];v2.pb(b[i]);}
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end());
      bool w=0;
      for (int i = 0; i < n; i++) if (v1[i]!=v2[i]) w=1;
      if (w) {cout << "NO\n";continue;}
      w=0;
      for (int i = n; i > 0; i--)
      {
          ll o=p[b[i]][p[b[i]].size()-1], c=geti(1,1,n,i);
          //cout << o << " " << c << "\n";
          ll u=get(1,1,n,o,c);
          if (u>b[i]) {w=1;break;}
          p[b[i]].erase(p[b[i]].end()-1);
          update(1,1,n,o);
      }
      if (w) {cout << "NO\n";continue;}
      cout << "YES\n";
  }
  return 0;
}