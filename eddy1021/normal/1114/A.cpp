#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void eat(LL& a, LL& b){
  LL c=min(a, b);
  a-=c;
  b-=c;
}
LL x, y, z, a, b, c;
int main(){
  cin>>a>>b>>c;
  cin>>x>>y>>z;
  eat(a, x);
  eat(b, x);
  eat(b, y);
  eat(c, x);
  eat(c, y);
  eat(c, z);
  puts(a>0 or b>0 or c>0?"NO":"YES");
}