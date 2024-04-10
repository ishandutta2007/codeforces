#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200,mod=1000000007,inv2=(mod+1)/2;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}
int Get_inv(int a,int p=mod){return Power(a,p-2,p);}

int n;
struct side{
  int y,next;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

void into(){
  scanf("%d",&n);
  for (int i=1;i<n;++i){
	int x,y;
	scanf("%d%d",&x,&y);
	Ins2(x,y);
  }
}

int c[N+9][N+9],ic[N+9][N+9];

void Get_c(){
  c[0][0]=ic[0][0]=1;
  for (int i=1;i<=n;++i){
	c[i][0]=c[i][i]=1;
	ic[i][0]=ic[i][i]=1;
	for (int j=1;j<i;++j) ic[i][j]=Get_inv(c[i][j]=add(c[i-1][j],c[i-1][j-1]));
  }
}

int pw[N+9],dp[N+9][N+9];

void Get_dp(){
  pw[0]=1;
  for (int i=1;i<=n;++i) pw[i]=mul(pw[i-1],inv2);
  for (int i=1;i<=n;++i)
	for (int j=1;j<i;++j){
	  int x=i-j,y=j;
	  for (int k=x;k<i;++k) sadd(dp[i][j],mul(c[k-1][x-1],pw[k]));
	}
}

int fa[N+9];

void Dfs_fa(int k,int fat){
  fa[k]=fat;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fat) Dfs_fa(e[i].y,k);
}

int ans;

void Dfs_ans(int k,int fa,int p,int now,int d){
  if (k<p) sadd(ans,now?dp[now+d][d]/*mul(c[now+d-1][d-1],ic[now+d][d])*/:1);
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fa) Dfs_ans(e[i].y,k,p,now,d+1);
}

void Get_ans(int k,int x){
  for (int p=x,t=0,now=0;p;t=p,p=fa[p],++now)
	for (int i=lin[p];i;i=e[i].next){
	  int y=e[i].y;
	  if (y==fa[p]) continue;
	  if (y==t) continue;
	  Dfs_ans(y,p,x,now,1);
	}
}

void Get_ans(int k){
  Dfs_fa(k,0);
  for (int i=1;i<=n;++i) Get_ans(k,i);
}

void work(){
  Get_c();
  Get_dp();
  for (int i=1;i<=n;++i) Get_ans(i);
  smul(ans,Get_inv(n));
}

void outo(){
  printf("%d\n",ans);
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