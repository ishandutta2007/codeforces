#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=250005,NC=(1<<19)+5,inf=0x3f3f3f3f;
struct DS{
	int f[NC],M;
	void build(int n){
		for(M=1;M<=n+2;M<<=1);
		memset(f,63,(M*2+3)<<2);
	}
	void upd(int x,int C){f[x+=M]=C;for(x>>=1;x;x>>=1)f[x]=std::min(f[x<<1],f[x<<1|1]);}
	int ask(int s,int t){
		int ans=inf;if(s>t)return ans;
		for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
			if(~s&1)chmin(ans,f[s^1]);
			if(t&1)chmin(ans,f[t^1]);
		}
		return ans;
	}
}tr1,tr2;
int st1[N],st2[N],top1,top2,a[N],dp[N];
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	top1=top2=0,tr1.build(n),tr2.build(n);
	for(int i=1;i<=n;++i){
		while(top1&&a[i]<a[st1[top1]])--top1;
		while(top2&&a[i]>a[st2[top2]])--top2;
		if(i==1)dp[i]=0;
		else{
			dp[i]=dp[i-1]+1;
			if(a[i]>a[i-1])chmin(dp[i],tr1.ask(std::upper_bound(st1+1,st1+top1+1,st2[top2])-st1,top1)+1);
			else chmin(dp[i],tr2.ask(std::upper_bound(st2+1,st2+top2+1,st1[top1])-st2,top2)+1);
		}
		st1[++top1]=i,st2[++top2]=i,tr1.upd(top1,dp[i]),tr2.upd(top2,dp[i]);
	}
	printf("%d\n",dp[n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}