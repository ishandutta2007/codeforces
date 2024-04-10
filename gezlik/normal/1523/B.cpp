#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1000;

int n,a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

void work(){
}

void outo(){
  printf("%d\n",n*3);
  for (int i=1;i<=n;i+=2){
	printf("1 %d %d\n",i,i+1);
	printf("2 %d %d\n",i,i+1);
	printf("1 %d %d\n",i,i+1);
	printf("1 %d %d\n",i,i+1);
	printf("2 %d %d\n",i,i+1);
	printf("1 %d %d\n",i,i+1);
  }
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