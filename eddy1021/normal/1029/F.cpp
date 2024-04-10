#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> s;
vector<LL> lena, lenb; 
LL a, b;
bool fit(LL x, LL y, const vector<LL>& len, LL c){
  int pos=upper_bound(len.begin(), len.end(), x)-len.begin();
  pos--;
  if(pos<0 or pos>=(int)len.size()) return false;
  if(len[pos]>x or c/len[pos]>y) return false;
  return true;
}
void check(LL x, LL y){
  // x<y
  if(fit(x, y, lena, a) or
     fit(x, y, lenb, b)){
    printf("%lld\n", (x+y)*2);
    exit(0);
  }
}
int main(){
  scanf("%lld%lld", &a, &b);
  LL val=a+b;
  for(LL i=1; i*i<=val; i++)
    if(val%i == 0)
      s.push_back(i);
  for(LL i=1; i*i<=a; i++)
    if(a%i == 0)
      lena.push_back(i);
  for(LL i=1; i*i<=b; i++)
    if(b%i == 0)
      lenb.push_back(i);
  reverse(s.begin(), s.end());
  for(auto cand: s)
    check(cand, val/cand);
}