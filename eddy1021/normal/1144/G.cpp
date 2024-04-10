#include <bits/stdc++.h>
using namespace std;
const int N=202020;
const int none=-1;
const int nope=-2;
int n, a[N], dp[N][2], bk[N][2], at[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  dp[1][0]=none;
  dp[1][1]=none;
  for(int i=1; i<n; i++){
    for(int j=0; j<2; j++) dp[i+1][j]=nope;
    for(int j=0; j<2; j++){
      if(dp[i][j] == nope) continue;
      auto upd0 = [&](int si, int sj, int val, int ti, int tj){
        if(dp[ti][tj] == none) return;
        if(dp[ti][tj] == nope or
           val > dp[ti][tj]){
          dp[ti][tj]=val;
          bk[ti][tj]=sj;
        }
      };
      auto upd1 = [&](int si, int sj, int val, int ti, int tj){
        if(dp[ti][tj] == none) return;
        if(dp[ti][tj] == nope or
           val < dp[ti][tj]){
          dp[ti][tj]=val;
          bk[ti][tj]=sj;
        }
      };
      // j == 0, a[i] as inc dp[i][j] as dec
      if(j == 0){
        for(int nj=0; nj<2; nj++){
          if(nj == 0){ // a[i+1] as inc
            if(a[i+1] > a[i])
              upd0(i, j, dp[i][j], i+1, nj);
          }else{ // a[i+1] as dec
            if(dp[i][j] == none or a[i+1] < dp[i][j])
              upd1(i, j, a[i], i+1, nj);
          }
        }
      }
      // j == 1, a[i] as dec dp[i][j] as inc
      else{
        for(int nj=0; nj<2; nj++){
          if(nj == 0){ // a[i+1] as inc
            if(dp[i][j] == none or a[i+1] > dp[i][j])
              upd0(i, j, a[i], i+1, nj);
          }else{ // a[i+1] as dec
            if(a[i+1] < a[i])
              upd1(i, j, dp[i][j], i+1, nj);
          }
        }
      }
    }
  }
  int gt=-1;
  for(int i=0; i<2; i++)
    if(dp[n][i] != nope)
      gt=i;
  if(gt == -1){
    puts("NO");
    exit(0);
  }
  for(int i=n; i>=1; i--){
    at[i]=gt;
    gt=bk[i][gt];
  }
  puts("YES");
  for(int i=1; i<=n; i++)
    printf("%d%c", at[i], " \n"[i==n]);
}