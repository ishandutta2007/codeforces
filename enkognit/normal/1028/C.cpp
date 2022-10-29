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

using namespace std;

const ll N=200001;
const pair<pll,pll> err=mp(mp(-1e9-1,-1e9-1),mp(-1e9-1,-1e9-1));

ll n,m,l,i,e,j,x,y,xx,yy,k,r;
pair<pll,pll> a[200001],b[200001],c[200001];bool t;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
  sort(a,a+n);
  //cout << 1;
  b[0]=a[0];
  for (int i=1;i<n;i++)
  {
   if (b[i-1].se.fi>=a[i].fi.fi && b[i-1].se.se>=a[i].fi.se && b[i-1].fi.se<=a[i].se.se)
   b[i]=mp(mp(max(a[i].fi.fi,b[i-1].fi.fi),
              max(a[i].fi.se,b[i-1].fi.se)),
           mp(min(b[i-1].se.fi,a[i].se.fi),
              min(b[i-1].se.se,a[i].se.se)));else
   b[i]=err;
   //cout << i << " ";
  }
  //for (i=0;i<n;i++) cout <<b[i].fi.fi << " " <<b[i].fi.se<< " " <<b[i].se.fi<<" "<<b[i].se.se << "\n";
  //system("pause");
  c[n-1]=a[n-1];
  for (i=n-2;i>=0;i--)
  {
   if (c[i+1].se.fi>=a[i].fi.fi && c[i+1].se.se>=a[i].fi.se && c[i+1].fi.se<=a[i].se.se)
   c[i]=mp(mp(max(a[i].fi.fi,c[i+1].fi.fi),max(a[i].fi.se,c[i+1].fi.se)),mp(min(c[i+1].se.fi,a[i].se.fi),min(c[i+1].se.se,a[i].se.se)));else c[i]=err;
  }
  //system("pause");
  if (b[n-2]!=err) cout << b[n-2].fi.fi << " " << b[n-2].fi.se << "\n";else
  if (c[1]!=err) cout << c[1].fi.fi << " " << c[1].fi.se << "\n";else
  {
   for (i=1;i<n-1;i++)
   {
    if (b[i-1].se.fi>=c[i+1].fi.fi && b[i-1].se.se>=c[i+1].fi.se && b[i-1].fi.se<=c[i+1].se.se)
    {
     cout << max(b[i-1].fi.fi,c[i+1].fi.fi) << " " << max(b[i-1].fi.se,c[i+1].fi.se) << "\n";return 0;
    }
   }
  }
  //system("pause");
  return 0;
}