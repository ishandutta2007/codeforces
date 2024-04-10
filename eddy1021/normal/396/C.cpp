#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300010;
const ll  MOD = 1000000007ll;

inline ll add(ll a, ll b)
{return (a+b)%MOD;}
inline ll mul(ll a, ll b)
{return (a*b)%MOD;}

struct BIT
{
  int sz;
  ll dat[MAXN];
  void upd(int id, ll d)
  {for(int i = id; i <= sz; i += i&-i) dat[i] = add(dat[i], d);}
  ll qry(int id)
  {
    ll res = 0ll;
    for(int i = id ; i > 0; i -= i & -i)
      res = add(res, dat[i]);
    return res;
  }
};

int n, p[MAXN], id[MAXN], ts;
int l[MAXN], r[MAXN];
ll dep[MAXN];
vector<int> g[MAXN];

BIT bit1, bit2;

void dfs(int u)
{
  id[u] = ++ts;
  l[u] = r[u] = id[u];
  for(int v:g[u])
  {
    dep[v] = dep[u]+1;
    dfs(v);
    r[u] = r[v];
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 2; i <= n; i++)
  {
    scanf("%d", p + i);
    g[p[i]].push_back(i);
  }
  dfs(1);
  bit1.sz = bit2.sz = n;
  int q;scanf("%d", &q);
  while(q--)
  {
    int typ;scanf("%d", &typ);
    if(typ == 1)
    {
      int v;
      ll x, k;
      scanf("%d%I64d%I64d", &v, &x, &k);
      bit1.upd(l[v], x);
      bit1.upd(r[v]+1, (-x+MOD));
      bit1.upd(l[v], mul(dep[v], k));
      bit1.upd(r[v]+1, (-mul(dep[v], k)+MOD));

      bit2.upd(l[v], (-k+MOD));
      bit2.upd(r[v]+1, -(-k+MOD)+MOD);

    }
    else
    {
      int v;
      scanf("%d", &v);
      ll res = bit1.qry(id[v]);
      res = add(res, mul(dep[v], bit2.qry(id[v])));
      printf("%I64d\n", res);
    }
  }
}