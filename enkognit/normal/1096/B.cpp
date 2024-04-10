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
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

ll n,m,k=0,a[200001],ans,l;
string s;


int main()
{
  //freopen("fence.in","r",stdin);
  //freopen("fence.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  int i=1,j=n-2,u=n-1;
  while (s[i]==s[i-1] && i<n-1) i++;
  while (s[j]==s[j+1] && j>0) j--;
  if (n==1) {cout << 1;exit(0);}
  if (s[0]==s[n-1]) cout << ((i*(n-j-1)%998244353)+i+(n-j-1)+1)%998244353; else cout << (i+(n-j-1)+1)%998244353;
  return 0;
}