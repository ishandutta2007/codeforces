#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

LL ans;

void work(){
  sort(a+1,a+n+1);
  ans=0;
  LL sum=0;
  for (int i=2;i<=n;++i){
	ans+=a[i]-a[i-1];
	ans-=1LL*a[i]*(i-1);
	ans+=sum;
	sum+=a[i];
  }
}

void outo(){
  printf("%lld\n",ans);
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