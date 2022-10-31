#include <bits/stdc++.h>
using namespace std;
const int N=(1<<18);
int n, r;
long long f[N], sum;
int main(){
  scanf("%d%d", &n, &r);
  n=(1<<n);
  for(int i=0; i<n; i++)
    scanf("%lld", &f[i]);
  sum=accumulate(f, f+n, 0LL);
  printf("%.12f\n", (double)sum/n);
  while(r--){
    int i, v;
    scanf("%d%d", &i, &v);
    sum-=f[i];
    f[i]=v;
    sum+=f[i];
    printf("%.12f\n", (double)sum/n);
  }
}