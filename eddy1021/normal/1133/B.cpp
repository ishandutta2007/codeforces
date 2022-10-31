#include <bits/stdc++.h>
using namespace std;
int n, k, x, c[111], ans;
int main(){
  scanf("%d%d", &n, &k); while(n --){
    scanf("%d", &x);
    if(c[(k-x%k)%k]) ans+=2, c[(k-x%k)%k]--;
    else c[x%k]++;
  }
  printf("%d\n", ans);
}