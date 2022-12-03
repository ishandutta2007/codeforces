#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=100000,B=20000,INF=numeric_limits<int>::max();

int n,m;
struct state{
  
  int a[5],v;
  
  int &operator [] (const int &p){return a[p];}
  const int &operator [] (const int &p)const{return a[p];}
  
}a[N+9];

void In(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i){
    for (int j=0;j<m;++j)
      scanf("%d",&a[i][j]);
    scanf("%d",&a[i].v);
  }
}

unordered_map<int,bitset<B+9>>mask;
bitset<B+9>tmp;
int ans;

void Get_ans(){
  ans=INF;
  for (int l=1,r;l<=n;l=r+1){
    r=min(l+B-1,n);
    mask.clear();
    for (int i=l;i<=r;++i)
      for (int j=0;j<m;++j)
        mask[a[i][j]][i-l]=1;
    for (int i=1;i<=n;++i){
      if (a[1].v+a[i].v>=ans) continue;
      tmp.set();
      for (int j=0;j<m;++j)
        if (mask.find(a[i][j])!=mask.end()) tmp&=~mask[a[i][j]];
      int p=l+tmp._Find_first();
      if (p<=r) ans=min(ans,a[i].v+a[p].v);
    }
  }
}

void Out(){
  printf("%d\n",ans==INF?-1:ans);
}

void work(){
  In();
  sort(a+1,a+n+1,[&](const state &a,const state &b){
    return a.v<b.v;
  });
  Get_ans();
  Out();
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}