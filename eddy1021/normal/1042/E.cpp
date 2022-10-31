#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1021;
const int mod=998244353;
inline int add(int x, int y){
  x+=y;
  return x>=mod?x-mod:x;
}
inline int mul(LL x, int y){
  x*=y;
  return x>=mod?x%mod:x;
}
inline int mpow(int x, int y){
  int r=1;
  while(y){
    if(y&1) r=mul(r, x);
    x=mul(x, x);
    y>>=1;
  }
  return r;
}
inline int inv(int x){
  return mpow(x, mod-2);
}
int n, m, qr, qc, a[N][N];
vector<int> li;
int go(int pxx, int px, int tot, int cx){
  int ret=pxx;
  ret=add(ret, mul(mul(cx, cx), tot));
  ret=add(ret, mul(mod-2, mul(px, cx)));
  return ret;
}
void solve(){
  vector<pair<int,pair<int,int>>> v;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      v.push_back({a[i][j], {i, j}});
  sort(v.begin(), v.end());
  int psum=0, pxx=0, pyy=0, px=0, py=0, tot=0;
  // (x1-x2)^2 = x1x1+x2x2-2x1x2
  for(size_t l=0, r=0; l<v.size(); l=r){
    while(r<v.size() and v[l].first == v[r].first) r++;
    int dtot=inv(tot);
    vector<int> wt;
    for(size_t i=l; i<r; i++){
      int cx=v[i].second.first;
      int cy=v[i].second.second;
      int cst=psum;
      cst=add(cst, go(pxx, px, tot, cx));
      cst=add(cst, go(pyy, py, tot, cy));
      int myans=mul(cst, dtot);
      if(cx == qr and cy == qc){
        printf("%d\n", myans);
        exit(0);
      }
      wt.push_back(myans);
    }
    for(size_t i=l; i<r; i++){
      int cx=v[i].second.first;
      int cy=v[i].second.second;
      int myans=wt[i-l];
      psum=add(psum, myans);
      pxx=add(pxx, mul(cx, cx));
      pyy=add(pyy, mul(cy, cy));
      px=add(px, cx);
      py=add(py, cy);
    }
    tot+=r-l;
  }
  assert(false);
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      scanf("%d", &a[i][j]);
  scanf("%d%d", &qr, &qc);
  solve();
}