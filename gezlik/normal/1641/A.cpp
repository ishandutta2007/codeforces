#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=200000;

int n;
int64 x;
multiset<int64>s;

void work(){
  scanf("%d%lld",&n,&x);
  for (int i=1;i<=n;++i){
    int64 v;
    scanf("%lld",&v);
    s.insert(v);
  }
  int ans=0;
  for (;!s.empty();){
    int64 t=*s.begin();
    s.erase(s.begin());
    if (s.find(t*x)!=s.end()){
      s.erase(s.find(t*x));
    }else ++ans;
  }
  printf("%lld\n",ans);
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;) work();
  return 0;
}