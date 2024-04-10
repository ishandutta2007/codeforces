#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sp system("pause")

using namespace std;

const ll N=1e18;

ll n,m,k,w,i,j;
ll a[2][300001],b[2][300001],c[2][300001],d[2][300001];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (i=0;i<2;i++)
  for (j=0;j<n;j++) cin >> a[i][j];
 for (i=0;i<2;i++)
  for (j=n-1;j>=0;j--)
 {
  b[i][j]=b[i][j+1]+(j+1)*a[i][j];
  c[i][j]=c[i][j+1]+(n-j)*a[i][j];
  d[i][j]=d[i][j+1]+a[i][j];
 }
 w=0;
 for (i=0,j=0;i<n;i++,j^=1)
 {
  m=k;
  m+=b[j][i]+i*d[j][i];
  m+=c[j^1][i]+(i+n)*d[j^1][i];
  w=max(w,m);
  k+=a[j][i]*(2*i+1);
  k+=a[j^1][i]*(2*i+2);
 }
 for (i=0;i<n;i++) w-=a[0][i]+a[1][i];
 cout << w;
 return 0;
}