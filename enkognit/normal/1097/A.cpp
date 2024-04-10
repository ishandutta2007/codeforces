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

int main()
{
  //freopen("missions.in","r",stdin);
  //freopen("missions.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> s;
  for (int i = 0; i < 5; i++)
  {
      cin >> d;
      if (d[0]==s[0] || d[1]==s[1]) {cout << "YES\n";exit(0);}
  }
  cout << "NO\n";
}