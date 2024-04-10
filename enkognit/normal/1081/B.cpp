#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double
#define y1 Enkognit

using namespace std;

ll n,m,i,j,k,l,a[100001],c[100001];
string s;map <ll,ll> t;
ll v[100001];
vector <ll> d[100001];

int main()
{
  //freopen("backforth.in","r",stdin);
  //freopen("backforth.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
   t[a[i]]++;
   if (a[i]>n-1) {cout << "Impossible\n";exit(0);}
   d[a[i]].pb(i);
  }
  sort(a,a+n);
  l=0;
  for (i=0;i<n;i++)
  {
   if (c[a[i]]) {c[a[i]]--;continue;}
   c[a[i]]=n-a[i]-1;
   if (n-a[i]-1<0) {cout << "Impossible\n";exit(0);}
   l++;
   if (d[a[i]].size()<n-a[i]) {cout << "Impossible\n";exit(0);}
   for (int j=0;j<n-a[i];j++) {v[d[a[i]][0]]=l;d[a[i]].erase(d[a[i]].begin());}
  }
  for (i=0;i<n;i++) if (c[a[i]]>0) {cout <<"Impossible\n";exit(0);}
  cout << "Possible\n";
  for (i=0;i<n;i++) cout << v[i] << " ";
}