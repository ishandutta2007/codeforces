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

ll n,m,j,l,r,k,sum[100001],ans,len=0;

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  string s;
  cin >> s;
  cin >> n;
  for (int i = 0; i < s.size()-1; i++)
  {
      if (s[i+1]!='*' && s[i+1]!='?' &&
          s[i]!='*' && s[i]!='?') l++;
  }
  if (s[s.size()-1]!='*' && s[s.size()-1]!='?') l++;
  //cout << l << "\n";
  string d="";
  s+=';';
  for (int i = 0; i < s.size()-1; i++)
  {
      if (s[i]=='*' || s[i]=='?') continue;
      if (s[i+1]!='*' && s[i+1]!='?') d+=s[i]; else
      if (s[i+1]=='?')
      {
          if (l<n) {d+=s[i];l++;}
      }else
      if (s[i+1]=='*')
      {
          if (l<n)
          while (l<n) {d+=s[i];l++;}
      }
  }
  //cout << l << "\n";
  if (d.size()==n) cout << d; else cout << "Impossible";
}