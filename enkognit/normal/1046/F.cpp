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

ll n,m,i,u,j,k,l,a[200001],b[200001];

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  cin >> k >> l;
  for (i=0;i<n;i++)
  {
   if (a[i]>k) m+=a[i]/(l+k)+(a[i]-(a[i]/(l+k)*(l+k))>k);
  }
  cout << m*l;
  return 0;
}