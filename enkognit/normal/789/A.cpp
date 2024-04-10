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

ll n,i,j,p,u,l,k,a[200001];

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> k;
  for (i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  for (i=0;i<n-1;i++)
  if (a[i]>0){l+=a[i]/k+(a[i]%k>0);a[i+1]-=((a[i]/k)+(a[i]%k>0))*k;}
  if (a[n-1]>0) while (a[n-1]>0) {l++;a[n-1]-=k*2;}
  cout << l;
  return 0;
}