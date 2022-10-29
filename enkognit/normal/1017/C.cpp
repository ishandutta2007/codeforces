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

ll n,m,k=0,l,x;
string s[2];

int main()
{
 //freopen("cows.in","r",stdin);
 //freopen("cows.out","w",stdout);
 cin >> n;
 k=(ll)sqrt((double)n);ll i;
 for (i=n-k;i>=0;i-=k)
 {
  for (int j=1;j<=k;j++) cout << i+j << " ";
 }
 n=i+k;
 for (i=i+1;i<=n;i++)if (i>0) cout << i << " ";
 return 0;
}