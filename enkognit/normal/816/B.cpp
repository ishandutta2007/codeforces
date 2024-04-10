#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;
ll a[400001];ll d[400001];vector<ll> b,c;
int n,m,k,x,y;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m >> k;
  for (int i=0;i<n;i++)
  {
   cin >> x >> y;
   a[x]++,a[y+1]--;
  }
  for (int i=2;i<200001;i++)a[i]+=a[i-1];
  for (int i=1;i<200001;i++)a[i]=a[i-1]+(a[i]>=m);
  for (int i=0;i<k;i++) {cin >> x >> y;cout << a[y]-a[x-1] << "\n";}
  return 0;
}