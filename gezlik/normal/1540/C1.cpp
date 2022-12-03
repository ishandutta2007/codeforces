#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}
int Get_inv(int a,int p=mod){return Power(a,p-2,p);}

int n,c[N+9],b[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&c[i]);
  for (int i=1;i<n;++i)
	scanf("%d",&b[i]);
}

void work(){
}

int a[N+9];

void Get_a(int q){
  for (int i=1;i<=n;++i) a[i]=a[i-1]+b[i-1];
  for (int i=1;i<=n;++i) a[i]+=a[i-1];
  for (int i=1;i<=n;++i) a[i]+=i*q;
}

int dp[N*N+9];

int Get_dp(int q){
  int sum=0;
  dp[0]=1;
  for (int i=1;i<=n;++i){
	sum+=c[i];
    for (int j=sum;j>=0;--j)
	  for (int k=1;k<=j&&k<=c[i];++k) sadd(dp[j],dp[j-k]);
	for (int j=0;j<=sum&&j<a[i];++j) dp[j]=0;
  }
  int res=0;
  for (int i=0;i<=sum;++i) sadd(res,dp[i]);
  return res;
}

void outo(){
  int cq;
  scanf("%d",&cq);
  for (;cq--;){
	int q;
	scanf("%d",&q);
	Get_a(q);
	printf("%d\n",Get_dp(q));
 }
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