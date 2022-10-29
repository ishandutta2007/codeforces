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
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
  }
  for (i=0;i<n;i++)
  {
   cin >> b[i];
  }
  j=1;
  k=b[0]+a[m-1];
  //cout << k;
  for (i=m-2;i>-1;i--)
  {
   while (b[j]+a[i]>k  && j<n) {j++;}
   if (j==n) {cout << i+2;exit(0);}
   j++;
  }
  cout << 1;
  return 0;
}