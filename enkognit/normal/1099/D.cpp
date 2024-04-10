#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

ll n,m,j,l,r,k,s[100001],vh[100001],h[100001],ans,asd=0;
bool t[100001],tt[100001];
vector <ll> v;
vector <ll> c[100001];
bool rt=0;

ll dfs(ll x)
{
    tt[x]=1;
    if (s[x]!=-1)
    {
        ll l=0;
        ll z=0;
        for (int i = 0; i < c[x].size(); i++)
            if (h[c[x][i]]>h[x])
        {
            asd=s[x];
            ll u=dfs(c[x][i]);
            if (!rt && u<s[x]) {cout << -1;exit(0);}
            if (!rt) {z++;l+=u;}
            rt=0;
        }
        return l-s[x]*z;
    }else
    if (s[x]==-1)
    {
        ll w=1e18,p=0,l=0;
        for (int i = 0; i < c[x].size(); i++)
            if (h[c[x][i]]>h[x])
        {
            w=min(s[c[x][i]],w);
            if (s[c[x][i]]<asd) {cout << -1;exit(0);}
        }
        for (int i = 0; i < c[x].size(); i++)
            if (h[c[x][i]]>h[x])
        {
            p++;
            l+=s[c[x][i]]-w;
        }
        if (p==0)rt=1;
        return l+w;
    }
}

void dfs2(ll x,ll k)
{
    t[x]=1;
    h[x]=k;
    for (int i = 0; i < c[x].size(); i++)
        if (!t[c[x][i]])
    {
        dfs2(c[x][i],k+1);
    }
}

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
      ll x;
      cin >> x;
      c[x].pb(i);
      c[i].pb(x);
  }
  for (int i = 1; i <= n; i++) cin >> s[i];
  dfs2(1,1);
  for (int i = 1; i <= n; i++) if ((s[i]==-1 && h[i]%2)||(s[i]!=-1 && h[i]%2==0)) {cout << -1;exit(0);}
  for (int i = 1; i <= n; i++)
      {

          if (s[i]!=-1) ans+=dfs(i);
      }
  cout << ans+s[1];
}