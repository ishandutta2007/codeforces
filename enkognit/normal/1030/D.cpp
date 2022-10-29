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

ll n,i,j,k,p,u,m;vector <ll> v;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  if (2*n*m%k!=0) {cout << "NO";exit(0);}
  for (i=2;i*i<=k;i++)
  {
   while (k%i==0)
   {
    k/=i;
    v.pb(i);
   }
  }v.pb(k);
  //for (i=0;i<v.size();i++) cout << v[i] << "\n";
  ll g=2*n,e=m;
  for (i=0;i<v.size();i++)
   if (g%v[i]==0) g/=v[i]; else e/=v[i];
  //cout << g << " " << e << "\n";
  if (g<=n && e<=m && g>0 && e>0) {cout << "YES\n0 0\n0 " << e << "\n" << g << " 0\n";exit(0);}
  g=n,e=m*2;
  for (i=0;i<v.size();i++)
   if (e%v[i]==0) e/=v[i]; else g/=v[i];
  if (g<=n && e<=m && g>0 && e>0) {cout << "YES\n0 0\n0 " << e << "\n" << g << " 0\n";exit(0);}
  cout << "NO";
  return 0;
}