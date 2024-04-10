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

ll n,m,k,l,i,j;
bool t[1000001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> l;
   if (!t[l+100000] && l!=0) {t[l+100000]=1;k++;}
  }
  cout << k;
  return 0;
}