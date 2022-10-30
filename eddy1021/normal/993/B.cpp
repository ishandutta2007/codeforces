#include <bits/stdc++.h>
using namespace std;
int n[2], a[2][12][2];
int ans;
void go(){
  for(int i=0; i<n[0]; i++){
    int amsk=0;
    for(int j=0; j<n[1]; j++){
      if(a[0][i][0] == a[1][j][0] and
         a[0][i][1] == a[1][j][1])
        continue;
      int cnt[12]={};
      cnt[a[0][i][0]]++;
      cnt[a[0][i][1]]++;
      cnt[a[1][j][0]]++;
      cnt[a[1][j][1]]++;
      for(int k=0; k<10; k++)
        if(cnt[k] == 2)
          amsk|=(1<<k);
    }
    if(__builtin_popcount(amsk) > 1){
      puts("-1");
      exit(0);
    }
    ans|=amsk;
  }
}
int main(){
  cin>>n[0]>>n[1];
  for(int i=0; i<2; i++)
    for(int j=0; j<n[i]; j++){
      cin>>a[i][j][0]>>a[i][j][1];
      if(a[i][j][1] < a[i][j][0])
        swap(a[i][j][0], a[i][j][1]);
    }
  for(int _=0; _<2; _++){
    go();
    for(int i=0; i<12; i++)
      for(int j=0; j<2; j++)
        swap(a[0][i][j], a[1][i][j]);
    swap(n[0], n[1]);
  }
  if(__builtin_popcount(ans) > 1)
    puts("0");
  else
    printf("%d\n", __lg(ans));
}