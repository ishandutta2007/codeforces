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

ll n,m,i,j,l,r,x,y,l1,l2,r1,r2,a[100001],b[100001];
bool t[100001];


int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i];b[a[i]]=i;}
  //sort(b,b+n,comp);
  t[b[n]]=1;
  for (i=n-1;i>0;i--)
  {
   //cout << b[i] << " ";
   bool u=0;
   for (ll j=b[i]+a[b[i]];j<=n && !u;j+=a[b[i]])
    if (a[j]>a[b[i]] && t[j]) u=1,t[j]=1;
   for (ll j=b[i]-a[b[i]];j>0 && !u;j-=a[b[i]])
    if (a[j]>a[b[i]] && t[j]) u=1,t[j]=1;
   //cout << u << "\n";
   if (!u) t[b[i]]=1;
  }
  for (i=1;i<=n;i++) if (!t[i]) cout << "A"; else cout << "B";
  return 0;
}