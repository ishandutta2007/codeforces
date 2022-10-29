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

ll n,k,m,i,j,o,z,l,p,ans,x,y;
//vector <ll> a[100001];
map <ll,map<ll,ll> > a;

ll binpow(ll p,ll o)
{
 ll l=0,y=1;
 while (l<o)
 {
  if (l>0 && l%2==0 && o/2>=l) l*=2,y*=y; else l++,y*=2;
 }
 return p*y;
}

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<m;i++) {cin >> x >> y;if (x>y) swap(x,y);a[x][y]=1;}
  ll u=0;
  for (j=1;j<n;j++)
   if (l==0)
   for (i=j+1;i<=n;i++)
    if (i!=j && !a[j][i]) {l=j;u=i;break;}
  if (l==0) {cout << "NO\n";exit(0);}
  cout << "YES\n";
  for (i=1,k=1;i<=n;i++,k++)
  {
   if (i==u) {cout << l << " ";k--;} else
   {if (i==l) k++;
   cout << k << " ";}
  }
  cout << "\n";
  for (i=1;i<=n;i++)
    if (i==u) cout << l << " "; else cout << i << " ";
  //cout << "\n" << l << " " << u << "\n";
 return 0;
}