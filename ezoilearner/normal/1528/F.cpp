#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

int n,K;
#define Maxn 300010

const int Mod=998244353;

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			b>>=1;
			a=1ll*a*a%Mod;
		}
		return res;
	}
}using namespace modular;

#define rez resize
vector<int> w[24];
void init_w(int lm=1<<18){
	w[17].rez(1<<17);w[17][0]=1;w[17][1]=Fast_Pow(3,(Mod-1)/lm);
	rep(i,2,lm/2-1)w[17][i]=mul(w[17][i-1],w[17][1]);
	per(i,16,0){
		w[i].rez(1<<i);
		for(int j=0;j<(1<<i);++j)w[i][j]=w[i+1][j<<1];
	}
}

int rev[Maxn],len,bit;
void NTT(int *A,int c){
	for(int i=0;i<len;++i)
		if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1,t=0;i<len;i<<=1,++t)
		for(int j=0;j<len;j+=i<<1)
			for(int k=0;k<i;++k){
				int x=A[j+k],y=mul(A[j+k+i],w[t][k]);
				A[j+k]=add(x,y);
				A[j+k+i]=dec(x,y);
			}
	if(c==-1){
		reverse(A+1,A+len);
		int ilen=Fast_Pow(len,Mod-2);
		rep(i,0,len-1)A[i]=mul(A[i],ilen);
	}
}

int f[Maxn],g[Maxn],fact[Maxn],ifac[Maxn],inv[Maxn];

int main(){
	scanf("%d%d",&n,&K);
	fact[0]=1;rep(i,1,K)fact[i]=mul(fact[i-1],i);
	ifac[K]=Fast_Pow(fact[K],Mod-2);
	per(i,K-1,0)ifac[i]=mul(ifac[i+1],i+1);
	inv[0]=inv[1]=1;
	rep(i,0,K){
		f[i]=Fast_Pow(i,K);
		f[i]=mul(f[i],ifac[i]);		
		if(i>1)inv[i]=mul(Mod-Mod/i,inv[Mod%i]);
	}
	rep(i,0,K){
		if(i&1)g[i]=dec(0,ifac[i]);
		else g[i]=ifac[i];
	}
	init_w();
	len=1;bit=0;
	while(len<=2*K)len<<=1,bit++;
	for(int i=0;i<len;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	NTT(f,1);NTT(g,1);
	rep(i,0,len-1)f[i]=mul(f[i],g[i]);
	NTT(f,-1);
	int ans=0,cur=Fast_Pow(n+1,n),in=Fast_Pow(n+1,Mod-2);
	rep(i,1,K){
		if(i>n)break;
		cur=mul(cur,n-i+1);
		cur=mul(cur,inv[i]);cur=mul(cur,in);
		f[i]=mul(f[i],fact[i]);
		ans=add(ans,mul(f[i],cur));
	}			
	printf("%d\n",ans);
	return 0;
}