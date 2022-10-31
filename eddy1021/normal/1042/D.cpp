#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=402020;
LL bit[N];
int lb(int x){ return x&(-x); }
void mod(int x){
  for(int i=x; i<N; i+=lb(i))
    bit[i]++;
}
int query(int x){
  int r=0;
  for(int i=x; i; i-=lb(i))
    r+=bit[i];
  return r;
}
vector<LL> li;
LL n, t, a[N], sa[N], ans;
inline int id(LL x){
  return lower_bound(li.begin(), li.end(), x)-li.begin()+1;
}
int main(){
  scanf("%lld%lld", &n, &t);
  for(int i=1; i<=n; i++){
    scanf("%lld", &a[i]);
    sa[i]=sa[i-1]+a[i];
    li.push_back(sa[i]);
    li.push_back(sa[i]-t);
  }
  li.push_back(0);
  sort(li.begin(), li.end());
  li.resize(unique(li.begin(), li.end())-li.begin());
  for(int i=1; i<=n; i++){
    mod(id(sa[i-1]));
    ans+=i-query(id(sa[i]-t));
  }
  cout<<ans<<endl;
}