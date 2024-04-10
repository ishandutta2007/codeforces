#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 400040
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const ll G=3;
const ll mod=998244353;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
const ll invG=qpow(G,mod-2);
const ll inv2=qpow(2LL,mod-2);
int n,m,tr[N];
ll g[N],f[N],h[N];
#define ck(x) (x>=mod?x-mod:x)
void NTT(ll *f,int flag,int n){
	for(int i=0;i<n;i++){
		if(i<tr[i])swap(f[i],f[tr[i]]);
	}
	for(int p=2;p<=n;p<<=1){
		int len=(p>>1);
		ll wn=qpow(flag?G:invG,(mod-1)/p);
		for(int k=0;k<n;k+=p){
			ll buf=1;
			for(int i=k;i<k+len;++i){
				ll tmp=f[i+len]*buf%mod;
				f[i+len]=ck(f[i]-tmp+mod);
				f[i]=ck(f[i]+tmp);
				buf=buf*wn%mod;
			}
		}
	}
	if(!flag){
		ll invn=qpow(n,mod-2);
		for(int i=0;i<n;i++){
			f[i]=f[i]*invn%mod;
		}
	}
}
void Inv(ll *f,ll *g,int m){
	if(m==1){
		g[0]=qpow(f[0],mod-2);
		return;
	}
	static ll w[N];
	Inv(f,g,(m+1)>>1);
	int n=1;
	while(n<(m<<1))n<<=1;
	for(int i=0;i<n;i++){
		tr[i]=((tr[i>>1]>>1)|((i&1)?n>>1:0));
		w[i]=f[i];
	}
	for(int i=m;i<n;i++)w[i]=0;
	NTT(w,1,n),NTT(g,1,n);
	for(int i=0;i<n;i++){
		g[i]=(2-w[i]*g[i]%mod+mod)*g[i]%mod;
	}
	NTT(g,0,n);
	for(int i=m;i<n;++i)g[i]=0;
}
void Sqrt(ll *f,ll *g,int m){
	static ll w[N],_g[N];
	if(m==1){
		g[0]=1;
		return;
	}
	Sqrt(f,g,(m+1)>>1);
	int n=1;
	while(n<(m<<1))n<<=1;
	for(int i=0;i<n;i++){
		_g[i]=0;
	}
	Inv(g,_g,m);
	for(int i=0;i<n;i++){
		tr[i]=((tr[i>>1]>>1)|((i&1)?n>>1:0));
		w[i]=f[i];
	}
	for(int i=m;i<n;++i)w[i]=0;
	NTT(w,1,n),NTT(_g,1,n),NTT(g,1,n);
	for(int i=0;i<n;i++){
		g[i]=(g[i]+w[i]*_g[i]%mod)*inv2%mod;
	}
	NTT(g,0,n);
	for(int i=m;i<n;i++)g[i]=0;
}
int main(){
	n=read(),m=read()+1;
	for(int i=1;i<=n;i++){
		int x=read();
		g[x]=1;
	}
	for(int i=0;i<m;i++){
		g[i]=(-4*g[i]+mod)%mod;
	}
	++g[0];
	Sqrt(g,h,m);
	h[0]=(h[0]+1)%mod;
	Inv(h,f,m);
	for(int i=1;i<m;i++){
		printf("%I64d\n",f[i]*2%mod);
	}
	return 0;
}