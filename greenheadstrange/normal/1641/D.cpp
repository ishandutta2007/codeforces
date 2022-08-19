// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;
mt19937 mrand(random_device{}()); 

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int n,m;
int a[maxn][10],st[maxn],maxw[(1<<20)+10],w[maxn];
const int inf=2.1e9;
int ans=inf;
int main() {
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      scanf("%d",&a[i][j]);
    }
    scanf("%d",&w[i]);
  }
  int T=20;
  int tt=0;
  while (clock()<2.8*CLOCKS_PER_SEC) {
    ll val=mrand();
    for (int i=0;i<(1<<T);i++) maxw[i]=inf;
    for (int i=0;i<n;i++) {
      st[i]=0;
      for (int j=0;j<m;j++) {
        int v=a[i][j]*val%2000000011%T;
        st[i]|=(1<<v);
      }
      if (__builtin_popcount(st[i])==m) {
        maxw[st[i]]=min(maxw[st[i]],w[i]);
      }
    }
    for (int i=0;i<T;i++) {
      for (int j=0;j<(1<<T);j++) if (j&(1<<i))
        maxw[j]=min(maxw[j],maxw[j-(1<<i)]);
    }
    for (int i=0;i<n;i++) {
      int t=(1<<T)-1-st[i];
      if (maxw[t]!=inf) {
        ans=min(ans,w[i]+maxw[t]);
      }
      maxw[st[i]]=min(maxw[st[i]],w[i]);
    }
  }
  if (ans==inf) ans=-1;
  printf("%d\n",ans);
}