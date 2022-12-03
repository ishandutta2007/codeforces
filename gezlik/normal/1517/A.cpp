#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int G=2050;

LL n;

void into(){
  scanf("%lld\n",&n);
  if (n%G) puts("-1");
  else{
	n/=G;
	int ans=0;
	for (;n;n/=10) ans+=n%10;
	printf("%d\n",ans);
  }
}

void work(){
}

void outo(){
}

int main(){
  int T;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}