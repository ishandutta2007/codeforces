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

using namespace std;

ll n,m,k,i,j,l,r;pll a[1000001];
string s[10001];
bool t[1001][1001];

int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  //if (n==3) {cout << "1 1 3\n";exit(0);}
  l=0;
  for (i=1;i<=n;i*=2)
  {
   bool u=0;
   if (n/(i*2)==1 && n/i*i>n/(i*2)*i*2) {u=1;cout << i << " ";}
   for (int j=1;j<=n/i-u;j+=2)
   {
    l++;cout << i << " ";
    if (l==n) exit(0);
   }
   if (u) {cout << n/i*i;exit(0);}
  }
}