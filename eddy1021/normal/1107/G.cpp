#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=303030;
LL n, a, d[N], c[N], ans, sum[N], lb[N], rb[N];
int p[N], lft[N], rgt[N];
bool in[N];
LL sqr(LL x){return x*x;}
int f(int x){return x==p[x]?x:p[x]=f(p[x]);}
void uni(int lhs, int rhs){
  lhs=f(lhs);
  rhs=f(rhs);
  // lhs -> rhs
  p[lhs]=rhs;
  lft[rhs]=lft[lhs];
  rb[rhs]=max(rb[rhs], sum[rhs]-c[rgt[rhs]]+rb[lhs]);
  lb[rhs]=max(lb[lhs], sum[lhs]-c[lft[lhs]]+lb[rhs]);
  sum[rhs]+=sum[lhs]-c[rgt[lhs]];
}
int main(){
  scanf("%lld%lld", &n, &a);
  for(int i=0; i<n; i++){
    scanf("%lld%lld", &d[i], &c[i]);
    c[i]=a-c[i];
  }
  //for(int i=0; i<n; i++)
    //printf("%lld %lld\n", d[i], c[i]);
  ans=*max_element(c, c+n);
  ans=max(ans, 0LL);
  vector<pair<LL, int>> wt;
  for(int i=0; i+1<n; i++){
    p[i]=i;
    lft[i]=i;
    rgt[i]=i+1;
    sum[i]=c[i]+c[i+1];
    lb[i]=max(0LL, c[i+1]);
    rb[i]=max(0LL, c[i]);
    wt.push_back({sqr(d[i+1]-d[i]), i});
  }
  sort(wt.begin(), wt.end());
  for(int _=0; _+1<n; _++){
    int i=wt[_].second;
    LL pen=sum[i]-wt[_].first;
    //cerr<<i<<" "<<pen<<endl;
    bool lok=false, rok=false;
    if(i>0 and in[i-1]) lok=true;
    if(i+2<n and in[i+1]) rok=true;
    if(lok) pen+=max(0LL, rb[f(i-1)]);
    if(rok) pen+=max(0LL, lb[f(i+1)]);
    ans=max(ans, pen);
    if(lok) uni(i-1, i);
    if(rok) uni(i, i+1);
    in[i]=true;
  }
  printf("%lld\n", ans);
}