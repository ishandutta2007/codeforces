#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
int main(){
  scanf("%d%d", &n, &k);
  b=k;
  while(n --){
    scanf("%d", &a);
    b=__gcd(b, a);
  }
  printf("%d\n", k/b);
  for(int i=0; i<k; i+=b) printf("%d ", i);
}