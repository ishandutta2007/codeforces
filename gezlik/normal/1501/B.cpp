#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,a[N+9],ans[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

void Get_ans(){
  int p=(1<<30)-1;
  for (int i=n;i>=1;--i){
	p=min(p,i-a[i]);
	ans[i]=p<i;
  }
}

void work(){
  Get_ans();
}

void outo(){
  for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
  puts("");
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