#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

ll n,m,j,l,r,k,ans, p[5202][5202];
string s;


ll reform(char c)
{
    if (c-48<10) return c-48; else
    if (c=='A') return 10; else
    if (c=='B') return 11; else
    if (c=='C') return 12; else
    if (c=='D') return 13; else
    if (c=='E') return 14; else
    if (c=='F') return 15;
}

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++)
      {
          ll o=reform(s[j]),d=4;
          while (d>0)
          {
              p[i+1][j*4+d]=o%2;
              o/=2;
              d--;
          }
      }
  }

  for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
          p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+p[i][j];
      }
  vector <ll> w;
  for (int i = 1; i <= sqrt(n); i++)
      if (n%i==0)
  {
      w.pb(i);
      if (i!=n/i) w.pb(n/i);
  }
  sort(w.begin(),w.end());
  for (int u = w.size()-1; u >= 0; u--)
  {
      ll z=w[u];
      bool tt=0;
      for (int i = z; i <= n; i+=z)
          if (!tt)
          for (int j = z; j <= n; j+=z)
              if (p[i][j]-p[i-z][j]-p[i][j-z]+p[i-z][j-z]!=0 &&
                   p[i][j]-p[i-z][j]-p[i][j-z]+p[i-z][j-z]!=z*z) {tt=1;break;}
      if (!tt) {cout << z;exit(0);}
  }
}