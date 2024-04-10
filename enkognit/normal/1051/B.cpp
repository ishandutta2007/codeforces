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

ll n,m,i,j,l=1e9,r,o,k=0;pll x,y;map <char,ll> a;char ch;map<char,bool> t;
string s;

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  if (n>=m)cout << "NO\n"; else {cout << "YES\n";
  for (i=n;i<m;i+=2)
  {
   cout << i << " " << i+1 << "\n";
  }}
  return 0;
}
/*cin >> n;
  for (j=0;j<n;j++)
  {
   vector <ll> l,r,c;
   cin >> s;
   for (i=0;i<n;i++)
    if (islower(s[i])) l.pb(i); else
    if (isupper(s[i])) r.pb(i); else
    c.pb(i);
   if (l.size()==0)
   {
    if (c.size()>1 && r.size()>0)s[c[0]]='a';else
    if (c.size()>0 && r.size()>1)s[r[0]]='a';
    if (c.size()>1 && r.size()==0)
    {

    }
   }
  }*/