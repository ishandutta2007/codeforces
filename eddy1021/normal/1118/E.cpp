#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
  scanf("%d%d", &n, &k);
  if(k*(k-1LL) < n){
    puts("NO");
    exit(0);
  }
  puts("YES");
  for(int i=0; i<n; i++)
    printf("%d %d\n", i%k+1, (i+1+i/k)%k+1);
}