#include<bits/stdc++.h>
using namespace std;
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
#define fl fwrite(o_str,1,o_t,stdout),o_t=0
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)fl;
}
inline void write(int x) {
	if(x>9)write(x/10);
	pc(x%10^48);
}
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc());
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int mod=998244353,maxn=6e5+10,inv2=499122177;
inline int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void NTT(int *x,int n,int f) {
	for(int i=0,j=0;i<n;i++) {
		if(i<j)swap(x[i],x[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1) {
		int m=i>>1,wn=qpow(3,(mod-1)/i);
		if(f==-1)wn=qpow(wn,mod-2);
		for(int j=0;j<n;j+=i)
			for(int k=0,w=1;k<m;k++) {
				int t=1ll*w*x[j+k+m]%mod;
				x[j+k+m]=(x[j+k]-t+mod)%mod;
				x[j+k]=(x[j+k]+t)%mod;
				w=1ll*w*wn%mod;
			}
	}
	if(f==-1)
		for(int i=0,t=qpow(n,mod-2);i<n;i++)
			x[i]=1ll*x[i]*t%mod;
}
int tmp[maxn],tmp2[maxn],tmp3[maxn];
void get_inv(int *a,int *b,int n) {
	if(n==1)return b[0]=qpow(a[0],mod-2),void();
	get_inv(a,b,(n+1)>>1);
	int N=1;
	while(N<n+n)N<<=1;
	for(int i=0;i<n;i++)tmp[i]=a[i];
	for(int i=n;i<N;i++)b[i]=tmp[i]=0;
	NTT(b,N,1),NTT(tmp,N,1);
	for(int i=0;i<N;i++)
		b[i]=b[i]*(2-1ll*b[i]*tmp[i]%mod+mod)%mod;
	NTT(b,N,-1);
	for(int i=n;i<N;i++)b[i]=0;
}
void get_sqrt(int *a,int *b,int n) {
	if(n==1)return b[0]=1,void();
	get_sqrt(a,b,(n+1)>>1);
	get_inv(b,tmp3,n);
	int N=1;
	while(N<n+n)N<<=1;
	for(int i=0;i<n;i++)tmp2[i]=a[i];
	for(int i=n;i<N;i++)tmp2[i]=0;
	NTT(tmp2,N,1),NTT(tmp3,N,1);
	for(int i=0;i<N;i++)tmp2[i]=1ll*tmp2[i]*tmp3[i]%mod;
	NTT(tmp2,N,-1);
	for(int i=0;i<n;i++)b[i]=1ll*inv2*(tmp2[i]+b[i])%mod;
	for(int i=n;i<N;i++)b[i]=0;
}////sdrhthtreh
int g[maxn],t1[maxn],t2[maxn];
int main() {
	int n=read(),m=read();
	for(int i=1;i<=n;i++)g[read()]=1;
	for(int i=0;i<=m;i++)t1[i]=(mod-4*g[i])%mod;
	t1[0]++;
	get_sqrt(t1,t2,m+1);
	t2[0]++;
	get_inv(t2,g,m+1);
	for(int i=1;i<=m;i++)write(g[i]*2%mod),pc('\n');
	fl;
	return 0;
}