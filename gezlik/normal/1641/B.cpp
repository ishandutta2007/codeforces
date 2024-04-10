#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=500;

int n,a[N*N+9];
map<int,int>mp;

void work(){
  scanf("%d",&n);
  mp.clear();
  for (int i=1;i<=n;++i){
    scanf("%d",&a[i]);
    ++mp[a[i]];
  }
  for (auto [x,y]:mp)
    if (y&1) {puts("-1");return;}
  vector<pair<int,int>>ans;
  vector<int>ans0;
  /*int p=1,q;
  for (int step=1,lim=n,cnt=0;step<=lim;++step){
    int p=step;
    for (q=p+1;q<=n;++i)
      if (a[q]==a[p]) break;
    auto Ins=[&](int p,int v){
      ans.emplace_back(p+cnt,v);
      ++cnt;
      for (int i=n;i>p;--i) a[i+2]=a[i];
      a[p+1]=a[p+2]=v;
    };
    for (int i=p+1,j=0;i<q;++i,++j)
      Ins(q+j,a[i]);
    int r=q+q-p;
    ans0.push_back(r-p);
    p=r;
  }*/
  for (int i=1,lim=n>>1,cnt=0;i<=lim;++i){
    int p=i,q;
    for (q=p+1;q<=n;++q)
      if (a[q]==a[p]) break;
    //printf("%d : %d : %d %d\n",i,cnt,p,q);
    for (int j=p+1,k=0;j<q;++j,++k)
      ans.emplace_back(q+k+cnt,a[j]);
    ans0.push_back(q-p<<1);
    cnt+=(q-p-1<<1)+1;
    reverse(a+p+1,a+q);
    for (int i=q;i<n;++i) a[i]=a[i+1];
    --n;
  }
  printf("%zd\n",ans.size());
  for (auto [x,y]:ans)
    printf("%d %d\n",x,y);
  printf("%zd\n",ans0.size());
  for (int t:ans0)
    printf("%d ",t);
  puts("");
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;) work();
  return 0;
}