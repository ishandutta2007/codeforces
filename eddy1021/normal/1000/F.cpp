#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505050;
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
pair<int,int> st[N<<2];
pair<int,int> better(const pair<int,int>& p1,
                     const pair<int,int>& p2){
  if(!p1.first) return p2;
  if(!p2.first) return p1;
  return min(p1, p2);
}
void mod(int no, int l, int r, int p, int a, int b){
  if(l == r){
    st[no]={a,b};
    return;
  }
  if(p <= mid) mod(L(no), l, mid, p, a, b);
  else mod(R(no), mid+1, r, p, a, b);
  st[no]=better(st[L(no)], st[R(no)]);
  //printf("no=%d l=%d r=%d st[no]={%d,%d}\n", no, l, r, st[no].first, st[no].second);
}
pair<int,int> query(int no, int l, int r, int ql, int qr){
  if(r<ql or l>qr) return {0, 0};
  if(ql<=l and r<=qr) return st[no];
  return better(query(L(no), l, mid, ql, qr),
                query(R(no), mid+1, r, ql, qr));
}
int n, a[N], q, ql[N], qr[N], ans[N], pre[N];
vector<int> qry[N];
int main(){
  scanf("%d", &n);
  //n=500000;
  for(int i=1; i<=n; i++)
    //a[i]=rand()%n+1;
    scanf("%d", &a[i]);
  scanf("%d", &q);
  //q=500000;
  for(int i=0; i<q; i++){
    scanf("%d%d", &ql[i], &qr[i]);
    //ql[i]=rand()%333+1;
    //qr[i]=n-rand()%333;
    qry[qr[i]].push_back(i);
  }
  for(int i=1; i<=n; i++){
    if(pre[a[i]])
      mod(1, 1, n, pre[a[i]], 0, 0);
    mod(1, 1, n, i, pre[a[i]]+1, a[i]);
    pre[a[i]]=i;
    for(int qi: qry[i]){
      pair<int,int> ret=query(1, 1, n, ql[qi], n);
      if(ret.first <= ql[qi])
        ans[qi]=ret.second;
    }
  }
  for(int i=0; i<q; i++)
    printf("%d\n", ans[i]);
}