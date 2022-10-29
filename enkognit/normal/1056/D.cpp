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

ll n,p=0,k,m,i,j,o,l,ans,x,y,a[100001],b[10001];
string s,d;
map <ll,ll> t;
vector <ll> c[100001];

bool comp(ll i,ll j)
{
 return a[i]>a[j];
}

void dfs(ll k,ll o)
{
 if ((c[k].size()==1 && c[k][0]==o) || c[k].size()==0) {a[k]=1;return;} else
 for (int i=0;i<c[k].size();i++)
  if (c[k][i]!=o)
 {
  dfs(c[k][i],k);
  a[k]+=a[c[k][i]];
 }
}

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=2;i<=n;i++)
  {
   cin >> x;
   c[x].pb(i);
   c[i].pb(x);
  }
  dfs(1,0);
  //system("pause");
  sort(a+1,a+n+1);
  for (i=1;i<=n;i++) cout << a[i] << " ";
  return 0;
}