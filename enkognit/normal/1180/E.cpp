#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, l, r, a[300005], b[300005], i, j;
ll d[6000001], t[6000001];

void push(ll h)
{
    if (t[h])
    {
        d[h*2]+=t[h];
        d[h*2+1]+=t[h];
        t[h*2]+=t[h];
        t[h*2+1]+=t[h];
        t[h]=0;
    }
}

void update(ll h,ll l,ll r,ll x,ll y,ll p)
{
    if (x>y) return;
    push(h);
    //cout << l << " " << r << " - " << x << " " << y << ":" << p << "\n";
    if (l==x && y==r)
    {
        t[h]+=p;
        push(h);
        d[h]=max(d[h*2],d[h*2+1]);
        return;
    }
    ll w=(l+r)/2;
    update(h*2,l,w,x,min(w,y),p);
    update(h*2+1,w+1,r,max(x,w+1),y,p);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(ll h,ll l,ll r)
{
    push(h);
    //cout << l << " " << r << ":" << d[h*2] << " " << d[h*2+1] << "\n";
    if (l==r) return l;
    ll w=(l+r)/2;
    if (d[h*2+1]>0) return get(h*2+1,w+1,r); else return get(h*2,l,w);
}

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
      cin >> a[i];
      update(1,1,1000000,1,a[i],1);
  }
  for (int i = 0; i < m; i++)
  {
      cin >> b[i];
      update(1,1,1000000,1,b[i],-1);
  }
  ll q;
  cin >> q;
  while (q--)
  {
      ll o, x, y;
      cin >> o >> x >> y;
      x--;
      if (o==1)
      {
          update(1,1,1000000,1,a[x],-1);
          a[x]=y;
          update(1,1,1000000,1,a[x],1);
      }else
      if (o==2)
      {
          update(1,1,1000000,1,b[x],1);
          b[x]=y;
          update(1,1,1000000,1,b[x],-1);
      }
      //cout << d[1] << "\n";
      if (d[1]<1) cout << "-1\n"; else
      cout << get(1,1,1000000) << "\n";
  }
  return 0;
}