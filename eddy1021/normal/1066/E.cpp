#include <bits/stdc++.h>
using namespace std;
const int N=202020;
const int mod=998244353;
int n, m, _sb[N], *sb;
char a[N], b[N];
int main(){
  scanf("%d%d", &n, &m);
  scanf("%s%s", a, b);
  sb=_sb+1;
  for(int i=0; i<m; i++)
    sb[i]=sb[i-1]+(b[i]-'0');
  int ans=0;
  for(int i=n-1, bns=1, j=m-1; i>=0 and j>=0; i--, j--, bns=(bns+bns)%mod)
    if(a[i]=='1')
      ans=(ans+(long long)bns*sb[j]%mod)%mod;
  cout<<ans<<endl;
}