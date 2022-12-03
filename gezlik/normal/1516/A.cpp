#include<bits/stdc++.h>
using namespace std;

const int N=100000;

int n,m,a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

void Get_a(){
  for (int i=1;i<n;++i){
	int t=min(a[i],m);
	m-=t;a[i]-=t;a[n]+=t;
  }
}

void work(){
  Get_a();
}

void outo(){
  for (int i=1;i<=n;++i)
	printf("%d ",a[i]);
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