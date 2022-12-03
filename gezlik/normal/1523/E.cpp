#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}
int Get_inv(int a,int p=mod){return Power(a,p-2,p);}int inv[N+9],fac[N+9],ifac[N+9];

void Get_inv(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=N;++i){
	inv[i]=mul(mod-mod/i,inv[mod%i]);
	fac[i]=mul(fac[i-1],i);
	ifac[i]=mul(ifac[i-1],inv[i]);
  }
}

int Get_c(int n,int m){return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}

int n,m;

void into(){
  scanf("%d%d",&n,&m);
}

int ans;

void work(){
  ans=fac[n];
  for (int i=1;i<=n;++i){
	if ((i-1)*m>=n) break;
	sadd(ans,mul(Get_c(n-1-(i-1)*m+i,i),mul(fac[i],fac[n-i])));
  }
}

void outo(){
  printf("%d\n",mul(ans,ifac[n]));
}

int main(){
  int T=1;
  scanf("%d",&T);
  Get_inv();
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}