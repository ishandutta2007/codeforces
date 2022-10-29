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

ll n,m,k=0,i,j,u,ans,a[1000001];
string s,d;

int main()
{
  //freopen("hex.in","r",stdin);
  //freopen("hex.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> k;
  for (i=1;i<=n;i++)
   if (n%i==0 && n/i<k) {cout << i*k+n/i;exit(0);}
  return 0;
}