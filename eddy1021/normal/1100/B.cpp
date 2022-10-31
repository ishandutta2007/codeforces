#include <bits/stdc++.h>
using namespace std;
const int N=101010;
int n, m, a[N], cnt[N], got;
int main(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++) scanf("%d", &a[i]);
  for(int i=0; i<m; i++){
    if(cnt[a[i]] == 0) got++;
    cnt[a[i]]++;
    if(got == n){
      putchar('1');
      for(int j=1; j<=n; j++){
        cnt[j]--;
        if(cnt[j] == 0) got --;
      }
    }else
      putchar('0');
  }
  puts("");
}