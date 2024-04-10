#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,K,C,D;
#define L 17
int ar[L][L<<1][L];
int inv[L];
int po[L][L<<1],B[L<<1][L];
int odd[32];
int pre[1<<16],all[1<<16];

namespace modular{
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			a=1ll*a*a%Mod;
			b>>=1;
		}
		return res;
	}
}using namespace modular;
void init(int i,int z){
	for(int j=0;j<(1<<(D+1));++j)
		if(odd[((1<<(D+1))-1-j)&z])po[i][j]=dec(0,inv[i]);
		else po[i][j]=inv[i];
}
int to[L];
void Mul(int *A,int *B,int *C){
	memset(to,0,sizeof(int)*(K+1));
	for(int i=0;i<=K;++i)
		for(int j=0;j<=K-i;++j)to[i+j]=add(to[i+j],mul(A[i],B[j]));
	memcpy(C,to,sizeof(int)*(K+1));
}
void Div(int *A,int *B,int *C){
	int t=Fast_Pow(B[0],Mod-2);
	for(int i=0;i<=K;++i){
		int tmp=A[i];
		for(int j=1;j<=i;++j)tmp=dec(tmp,mul(B[j],to[i-j]));
		to[i]=mul(tmp,t);
	}
	memcpy(C,to,sizeof(int)*(K+1));
}
void Fast_Pow(int *res,int *a,int b){
	while(b){
		if(b&1)Mul(res,a,res);
		Mul(a,a,a);
		b>>=1;
	}
}
int cnt[16][L];
void solve(int tmp,int c){
	if(!cnt[tmp][c])return;
	int zjr=cnt[tmp][c];
	tmp+=(1<<(c+D));int pre=tmp;
	for(int i=0;i<=K;++i){
		int z=(pre^tmp)&((1<<D)-1);
		if(!(tmp&(1<<(c+D))))z+=(1<<D);
		init(i,z);
		tmp--;
		for(int j=0;j<(1<<(D+1));++j)B[j][i]=po[i][j];
	}
	for(int i=0;i<(1<<(D+1));++i)Fast_Pow(ar[c][i],B[i],zjr);
}

int lowbit(int x){return x&(-x);}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int bel[1<<16],F[1<<16][L],ans[1<<16],fjz[1<<16],pf[16];
void FWT(int *A){
	for(int i=1;i<(1<<D);i<<=1)
		for(int j=0;j<(1<<D);j+=(i<<1))
			for(int k=0;k<i;++k){
				int x=add(A[j+k],A[j+k+i]);
				int y=dec(A[j+k+i],A[j+k]);
				A[j+k]=mul(x,inv[2]);
				A[j+k+i]=mul(y,inv[2]);
			}
}

int main(){
	int Ans=0;
	pf[0]=1;
	for(int i=1;i<16;++i)pf[i]=pf[i-1]^(1<<i);
	for(int i=0;i<16;++i)bel[1<<i]=i;
	for(int i=1;i<32;++i)odd[i]=odd[i^lowbit(i)]^1;
	inv[0]=inv[1]=1;
	for(int i=2;i<L;++i)inv[i]=mul(inv[Mod%i],Mod-Mod/i);
	for(int i=2;i<L;++i)inv[i]=mul(inv[i-1],inv[i]);
	rd(n);rd(K);rd(C);
	int x;
	D=0;while((1<<D)<K)D++;
	bool flag=false;
	if(C==D){
		flag=true;
		C++;
	}
	for(int i=1;i<=n;++i){
		rd(x);
		Ans^=x;
		all[x]++;
	}
	pre[0]=0;
	for(int i=1;i<(1<<(C-D));++i)pre[i]=bel[lowbit(i)];
	for(int i=0;i<(1<<(C-D));++i)
		for(int j=0;j<(1<<D);++j)
			cnt[j][pre[i]]+=all[(i<<D)|j];
	for(int i=0;i<C-D;++i)
		for(int j=0;j<(1<<(D+1));++j)ar[i][j][0]=1;
	for(int i=0;i<(1<<D);++i)
		for(int j=0;j<C-D;++j)solve(i,j);
	for(int i=0;i<C-D;++i)
		for(int j=0;j<(1<<D);++j)
			for(int k=0;k<=K;++k){
				int t1=add(ar[i][j][k],ar[i][j+(1<<D)][k]);
				int t2=dec(ar[i][j+(1<<D)][k],ar[i][j][k]);
				ar[i][j][k]=mul(t1,inv[2]);ar[i][j+(1<<D)][k]=mul(t2,inv[2]);
			}
	for(int i=0;i<(1<<D);++i){
		F[i][0]=1;
		for(int j=0;j<C-D;++j)Mul(F[i],ar[j][i],F[i]);
		ans[i]=F[i][K];
		for(int j=1;j<(1<<(C-D));++j){
			Div(F[((j^lowbit(j))<<D)|i],ar[pre[j]][i],F[(j<<D)|i]);
			Mul(F[(j<<D)|i],ar[pre[j]][i|(1<<D)],F[(j<<D)|i]);
			ans[(j<<D)|i]=F[(j<<D)|i][K];
		}
	}
	for(int i=0;i<(1<<(C-D));++i){
		int sta=0;
		for(int j=0;j<(C-D);++j)
			if(i&(1<<j))sta^=pf[j];
		FWT(ans+i*(1<<D));
		for(int j=0;j<(1<<D);++j)fjz[(sta<<D)^j^Ans]=ans[i*(1<<D)+j];
	}
	int fact=1;
	for(int i=1;i<=K;++i)fact=mul(fact,i);
	fact=mul(fact,Fast_Pow(n,1ll*(Mod-2)*K%(Mod-1)));
	if(flag)C--;
	for(int i=0;i<(1<<C);++i)printf("%d ",mul(fact,fjz[i]));
	return 0;
}/*
4 2 3
7 2 5 6
*/