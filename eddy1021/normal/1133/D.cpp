#include <bits/stdc++.h>
using namespace std;
const int N=202020;
map<pair<int,int>, int> v;
int n, a[N], b[N];
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++) scanf("%d", &b[i]);
  int base=0;
  for(int i=0; i<n; i++){
    // d a[i] + b[i] = 0
    // a = -b[i] / a[i]
    int p=-b[i], q=a[i];
    if(q == 0){
      if(p == 0) base++;
      continue;
    }
    if(q<0) p=-p, q=-q;
    int g=__gcd(abs(p), abs(q));
    p/=g; q/=g;
    v[{p, q}]++;
  }
  int ans=0;
  for(auto i: v) ans=max(ans, i.second);
  printf("%d\n", ans + base);
}