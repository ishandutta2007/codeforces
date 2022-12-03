#include<bits/stdc++.h>
using namespace std;

const int N=200000;

int n,a[N+9],sum;

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	sum+=a[i];
  }
}

int dp[N+9];

void Get_ans(){
  if (sum&1) {puts("0");return;}
  dp[0]=1;
  for (int i=1;i<=n;++i)
	for (int j=sum;j>=a[i];--j) dp[j]|=dp[j-a[i]];
  if (!dp[sum>>1]) {puts("0");return;}
  int p=0;
  a[0]=N;
  for (int i=1;i<=n;++i){
	int c=0;
	for (;a[i]&1^1;a[i]>>=1) ++c;
	a[i]=c;
	if (a[i]<a[p]) p=i;
  }
  printf("1\n%d\n",p);
}

void work(){
  Get_ans();
}

void outo(){
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}