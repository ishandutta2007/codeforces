#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,a[N+9],cnt[30];

void into(){
  scanf("%d",&n);
  for (int i=0;i<30;++i) cnt[i]=0;
  for (int i=1;i<=n;++i){
    scanf("%d",&a[i]);
    for (int j=0;j<30;++j)
      if (a[i]>>j&1) ++cnt[j];
  }
}

void work(){
}

void outo(){
  int g=0;
  for (int i=0;i<30;++i) g=__gcd(g,cnt[i]);
  for (int i=1;i<=n;++i)
    if (g%i==0) printf("%d ",i);
  puts("");
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}