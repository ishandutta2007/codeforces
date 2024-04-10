#include <bits/stdc++.h>
using namespace std;
const int K=1021;
int cnt[K], n, a[22][22];
void no(){
  puts("NO");
  exit(0);
}
int main(){
  scanf("%d", &n);
  for(int i=0, x; i<n*n; i++){
    scanf("%d", &x);
    cnt[x]++;
  }
  int cand=0;
  for(int i=1; i+i<=n; i++)
    for(int j=1; j+j<=n; j++){
      while(cand<K and cnt[cand]<4) cand++;
      if(cand == K) no();
      cnt[cand]-=4;
      a[i][j]=a[n-i+1][j]=a[i][n-j+1]=a[n-i+1][n-j+1]=cand;
    }
  if(n&1){
    cand=0;
    for(int i=1; i+i<=n; i++){
      while(cand<K and cnt[cand]<2) cand++;
      if(cand == K) no();
      cnt[cand]-=2;
      a[(n+1)/2][i]=a[(n+1)/2][n-i+1]=cand;

      while(cand<K and cnt[cand]<2) cand++;
      if(cand == K) no();
      cnt[cand]-=2;
      a[i][(n+1)/2]=a[n-i+1][(n+1)/2]=cand;
    }
    cand=0;
    while(cand<K and cnt[cand]==0) cand++;
    if(cand == K) no();
    a[(n+1)/2][(n+1)/2]=cand;
  }
  puts("YES");
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      printf("%d%c", a[i][j], " \n"[j==n]);
}