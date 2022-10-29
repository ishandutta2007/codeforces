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

ll n,m,k,l,r,i,j,w,x,y,p,b[200001];
string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> s;
  d="aouien";
  for (i=1;i<s.size();i++)
  if ((d.find(s[i])==string::npos && d.find(s[i-1])==string::npos)||(d.find(s[i-1])==string::npos && s[i]=='n')) {cout << "NO";exit(0);}
  if (d.find(s[s.size()-1])==string::npos) {cout << "NO";exit(0);}
  cout << "YES";
  return 0;
}