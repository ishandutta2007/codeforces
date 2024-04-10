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

using namespace std;

ll n,m,i,j,k,l=0,x,y,h=1,r,o,p=0,a[500001];
string s;
map <ll,ll> t;
ll u;
vector <ll> v;

int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  if (n==1) {cout <<"1 0";exit(0);}
  ll p=n;
  for (i=2;i<=p;i++)
  {
   if (n%i==0) v.pb(i),h*=i;
   while (n%i==0) n/=i,t[i]++;
  }
  l=t[v[0]];
  for (i=1;i<v.size();i++)
   {if (l!=t[v[i]]) u=1;if (l<t[v[i]]) l=t[v[i]];}
  if (l==1) {cout << p << " 0";exit(0);}
  j=1;o=0;
  while (j<l)
  {
   j*=2;
   o++;
  }
  if (j!=l) u=1;
  //cout << o << "\n";
  cout << h << " " << o+u;
  return 0;
}