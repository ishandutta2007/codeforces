#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define len length()
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

ll n,m,i,j,l,r,k;
vector <ll> v;
string s,d;
ll a[100001];

void rec(ll h,ll k1,ll k2)
{
    if (h==n) {if (k1%360==k2%360) {cout << "YES\n";exit(0);}return;}
    rec(h+1,k1,k2+a[h]);
    rec(h+1,k1+a[h],k2);
}

map <ll,ll> t1,t2;

int main()
{
  //freopen("missions.in","r",stdin);
  //freopen("missions.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      string s;
      cin >> s;
      ll k=0;
      bool tt=0;
      for (int j = 0; j < s.size(); j++)
      {
         if (s[j]=='(') k++; else k--;
         if (k<0) tt=1;
      }
      //cout << k << "\n";
      if (!tt && k>=0) t1[k]++; else
      {
          ll p=0;
          bool tp=0;
          for (int j = s.size()-1; j >=0; j--)
          {
              if (s[j]=='(') p--; else p++;
              if (p<0) tp=1;
          }
          if (!tp && p>=0) t2[p]++;
      }
  }
  ll ans=0;
  ans+=t1[0]/2;
  for (int i = 1; i <= 5*1e5; i++)
  {
      ans+=min(t1[i],t2[i]);
  }
  cout << ans;
  return 0;
}