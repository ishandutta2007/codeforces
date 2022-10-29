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

ll n,m,k=0,l,x,k00,k11,k10,k01;
string s[2];

int main()
{
 //freopen("cows.in","r",stdin);
 //freopen("cows.out","w",stdout);
 cin >> n;
 cin >> s[0];
 cin >> s[1];
 for (int i=0;i<n;i++)
  if (s[0][i]=='0' && s[1][i]=='1') k01++; else
  if (s[0][i]=='1' && s[1][i]=='0') k10++; else
  if (s[0][i]=='0' && s[1][i]=='0') k00++; else
  if (s[0][i]=='1' && s[1][i]=='1') k11++;
 cout << k01*k10+k00*k10+k00*k11;
 return 0;
}