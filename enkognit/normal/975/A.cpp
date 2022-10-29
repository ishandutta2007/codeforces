#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pu push
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,i,j,k,l;
bool t[1001];
string s,d[1001];

int main()
{
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> s;
   for (int j=0;j<s.len;j++)
    if (d[i].find(s[j])==-1) d[i]+=s[j];
   for (int j=0;j<d[i].len-1;j++)
    for (int u=j+1;u<d[i].len;u++)
     if (d[i][j]>d[i][u]) swap(d[i][j],d[i][u]);
  }
  l=n;
  for (i=1;i<n;i++)
   if (!t[i])
   for (j=i+1;j<=n;j++)
    if (d[i]==d[j] && !t[j]) {l--;t[j]=1;}
  cout << l;
  return 0;
}