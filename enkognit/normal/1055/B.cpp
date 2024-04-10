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

using namespace std;

ll n,k,m,i,l,x,y,a[100001];
string s,d;
bool t[100001];
char c;

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=1;i<=n;i++)
  {
   if (a[i]>k) t[i]=1;
   if (a[i]>k && a[i-1]<=k) l++;
  }
  for (i=0;i<m;i++)
  {
   cin >> x;
   if (x==0) cout << l << "\n"; else
   {
    ll y,u;
    cin >> y >> u;
    a[y]+=u;
    if (!t[y] && a[y]>k)
    {
     t[y]=1;
     if (t[y-1]==1 && t[y+1]==1) l--;else
     if (t[y-1]==0 && t[y+1]==0) l++;
    }
   }
  }
  return 0;
}