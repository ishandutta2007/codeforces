#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

void into(){
}

void work(){
}

LL Get_ans(LL a,LL n,LL p){
  if (a*n<p) return max(a,p-a*n);
  LL z=a*n/p-(a*n%p<a*(p/a-1));
  return Get_ans(p%a,z,a);
}

void outo(){
  int cq;
  scanf("%d",&cq);
  for (;cq--;){
	LL a,n,p,d;
	scanf("%lld%lld%lld%lld",&a,&n,&p,&d);
	a%=p;
	if (a<=d) {puts("YES");continue;}
	if (a*n<=p) {puts(a<=d?"YES":"NO");continue;}
	puts(Get_ans(a,n,p)<=d?"YES":"NO");
  }
}

int main(){
  //freopen("b.in","r",stdin);
  //freopen("b.out","w",stdout);
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}