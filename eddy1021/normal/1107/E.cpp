#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
const LL inf=1e16;
int n;
char b[N];
LL a[N];
LL dp[N][N][N][2];
bool gt[N][N][N][2];
LL DP(int l, int r, int con, int g){
  if(l>r) return a[con];
  if(gt[l][r][con][g]) return dp[l][r][con][g];
  LL ret=-inf;
  if(b[l]-'0' == g)
    ret=max(ret, DP(l+1, r, con+1, g));
  for(int til=l; til<=r; til++){
    if(con==0 and til==r) break;
    LL bst=-inf;
    for(int ng=0; ng<2; ng++)
      bst=max(bst, DP(l, til, 0, ng));
    ret=max(ret, bst+DP(til+1, r, con, g));
  }
  gt[l][r][con][g]=true;
  return dp[l][r][con][g]=ret;
}
int main(){
  scanf("%d", &n);
  scanf("%s", b);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  //n=100;
  //for(int i=0; i<100; i++) b[i]=(i/50)+'0';
  //for(int i=1; i<=n; i++) a[i]=rand();
  printf("%lld\n", max(DP(0, n-1, 0, 0),
                       DP(0, n-1, 0, 1)));
}