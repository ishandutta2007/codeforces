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

using namespace std;

ll n,m,i,j,k,l=0,x,y,h,r,o,p=0,a[100001];
vector <ll> b;
map <ll,pll> t;

int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
  }
  a[n]=1e9;
  a[n+1]=1e9;
  i=0;
  for (i=0;i<m;i++)
  {
   cin >> x >> y >> h;
   if (x==1) b.pb(y);
  }
  sort(a,a+n);
  sort(b.begin(),b.end());
  r=1e9;
  for (i=0;i<=n;i++)
  {
   ll y=upper_bound(b.begin(),b.end(),a[i]-1)-b.begin();
   //cout << b[y] << "\n";
   r=min(r,b.size()-y+i);
  }
  cout << r;
  return 0;
}
/*l=1;
  i=2;
  j=n;r=1;
  for (i=2;i<=n;i++)
  {
   j=n;
   if (j%i==0) l++;
   while (j%i==0) j/=i;
  }
  cout << l;*/