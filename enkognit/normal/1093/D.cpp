#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

const ll MOD=998244353;

ll n,m,k=0,i,j,xx,yy,p,u,ans,x,y,q;
queue <ll> g;
vector <ll> c[300001];
short t[300001];

ll binpow(ll n,ll p,ll r)
{
 ll l=1,o=0;
 while (o<p)
 {
  if (o*2<=p && o>0) l*=l,l%=r,o*=2; else l*=n,l%=r,o++;
 }
 return l;
}

short o(short x)
{
 if (x==1) return 2; else return 1;
}

void dfs(ll num,short ind)
{
 if (u) return;
 if (t[num]>0)
 {
  if (t[num]!=ind) u=1;
  return;
 }else if (ind==1) {k++;}
 t[num]=ind;
 q++;
 for (int i=0;i<c[num].size();i++)
 {
  if (t[c[num][i]]>0 && t[c[num][i]]==ind) {u=1;return;}
  dfs(c[num][i],o(ind));
 }
}

int main()
{
  //freopen("hps.in","r",stdin);
  //freopen("hps.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> p;
  while (p>0)
  {
   p--;
   ans=1;
   cin >> n >> m;
   for (int i=0;i<m;i++)
   {
    ll x,y;
    cin >> x >> y;
    c[x].pb(y);
    c[y].pb(x);
   }
   for (int i=1;i<=n;i++)
    if (!t[i])
    {
     u=0;
     k=0;
     q=0;
     dfs(i,1);
     if (!u)
        {ans=((ans*(binpow(2,k,MOD)+binpow(2,q-k,MOD))))%MOD;}
     else {ans=0;break;}
    }
   for (int i=0;i<=n;i++) {c[i].clear();t[i]=0;}
   if (u)cout << 0 << "\n";else
   cout << ans%MOD << "\n";
  }
  return 0;
}