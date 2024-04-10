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
const int N=1000005;typedef long long ll;
ll a[N];int cnt[N],st1[N],top1,st2[N],top2,A[N],B[N];
struct VAL{int v,c;}f[N<<2];int tag[N<<2],M;
inline VAL merge(const VAL &a,const VAL &b){return a.v==b.v?(VAL){a.v,a.c+b.c}:a.v>b.v?a:b;}
inline void pushup(int u){f[u]=merge(f[u<<1],f[u<<1|1]),f[u].v+=tag[u];}
void build(int n){
	for(int i=1;i<=M*2;++i)tag[i]=0;
	for(int i=1;i<=n;++i)f[i+M]={0,1};
	for(int i=M-1;i>=1;--i)f[i]=merge(f[i<<1],f[i<<1|1]);
}
void Update(int s,int t,int C){
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1,pushup(s),pushup(t)){
		if(~s&1)f[s^1].v+=C,tag[s^1]+=C;
		if(t&1)f[t^1].v+=C,tag[t^1]+=C;
	}
	s>>=1;while(s)pushup(s),s>>=1;
}
ll ans;
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)cnt[i]=__builtin_popcountll(a[i]);
	for(int i=n;i>=1;--i){
		while(top1&&a[i]>a[st1[top1]])--top1,++A[i];
		st1[++top1]=i;
		while(top2&&a[i]<a[st2[top2]])--top2,++B[i];
		st2[++top2]=i;
	}
	for(M=1;M<=n+2;M<<=1);
	for(int b=0;b<=60;++b){
		build(n);st1[0]=st2[0]=n+1,top1=top2=0;
		for(int i=n;i>=1;--i){
			for(int j=0;j<A[i];++j){
				if(cnt[st1[top1]]==b)Update(st1[top1],st1[top1-1]-1,-1);
				--top1;
			}
			if(cnt[i]==b)Update(i,st1[top1]-1,1);
			st1[++top1]=i;
			for(int j=0;j<B[i];++j){
				if(cnt[st2[top2]]==b)Update(st2[top2],st2[top2-1]-1,-1);
				--top2;
			}
			if(cnt[i]==b)Update(i,st2[top2]-1,1);
			st2[++top2]=i;
			if(f[1].v==2)ans+=f[1].c;
		}
	}
	printf("%lld\n",ans);
	return 0;
}