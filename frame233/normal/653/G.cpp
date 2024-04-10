#include<bits/stdc++.h>
const int BUF_SIZ=1<<18;
char ibuf[BUF_SIZ],*iS=ibuf,*iT=ibuf;
#define getchar() (iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,BUF_SIZ,stdin)),iS==iT?EOF:*iS++)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
bool pr[N];int p[N],pos,md[N],a[N],pw[N];
void sieve(){
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,md[i]=pos;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1,md[i*p[j]]=j;
			if(i%p[j]==0)break;
		}
	}
}
int pool[200005],*P=pool,*cnt[80005],L[80005],pre[25],suf[25],sum[N];
int main(){
	sieve(),init();
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=pw[i-1],add(pw[i],pw[i]);
	for(int i=1;i<=pos;++i){
		int c=0;ll cur=1;
		while(cur*p[i]<1e6)cur*=p[i],++c;
		cnt[i]=P,P+=c+1,L[i]=c+1;
	}
	int n;read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		int last=0,c=0;
		for(int x=a[i];x>1;x/=p[md[x]]){
			if(md[x]==last)++c;
			else{
				if(last)++cnt[last][c];
				last=md[x],c=1;
			}
		}
		if(last)++cnt[last][c];
	}
	for(int i=n-1;i>=0;--i)sum[i]=C(n-1,i),add(sum[i],sum[i+1]);
	int ans=0;
	for(int t=1;t<=pos;++t){
		cnt[t][0]=n;for(int i=1;i<L[t];++i)cnt[t][0]-=cnt[t][i];
		pre[0]=cnt[t][0];for(int i=1;i<L[t];++i)pre[i]=pre[i-1]+cnt[t][i];
		suf[L[t]-1]=cnt[t][L[t]-1];for(int i=L[t]-2;i>=0;--i)suf[i]=suf[i+1]+cnt[t][i];
		for(int i=0;i+1<L[t];++i){int _n=pre[i],_m=suf[i+1];add(ans,(1LL*_n*sum[_n]+1LL*_m*sum[_m+1])%mod);}
	}
	printf("%d\n",ans);
	return 0;
}