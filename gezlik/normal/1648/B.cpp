#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=1000000;

int n,m,cnt[N+9],pre[N+9];

void work(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=m;++i) cnt[i]=0;
  for (int i=1;i<=n;++i){
    int x;
    scanf("%d",&x);
    ++cnt[x];
  }
  for (int i=1;i<=m;++i) pre[i]=pre[i-1]+cnt[i];
  for (int i=1;i<=m;++i){
    if (!cnt[i]) continue;
    for (int j=i;j<=m;j+=i){
      int r=min(j+i-1,m);
      int c=pre[r]-pre[j-1];
      if (c&&!cnt[j/i]) return (void)(puts("No"));
    }
  }
  puts("Yes");
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;) work();
  return 0;
}