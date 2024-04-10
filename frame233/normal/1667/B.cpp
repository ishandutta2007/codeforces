#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=500005;typedef long long ll;
ll a[N],pre[N],t[N];int dp[N],c[N];
void add(int x,int C){for(;x<N;x+=lowbit(x))chmax(c[x],C);}
int ask(int x){int ans=-1e9;for(;x;x-=lowbit(x))chmax(ans,c[x]);return ans;}
void MAIN(){
	int n;read(n);int pos=0;
	for(int i=1;i<=n;++i)read(a[i]),pre[i]=pre[i-1]+a[i];
	for(int i=0;i<=n;++i)t[++pos]=pre[i];
	std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=0;i<=n;++i)pre[i]=std::lower_bound(t+1,t+pos+1,pre[i])-t;
	memset(c,-63,(pos+3)<<2),add(pre[0],0),dp[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=std::max(dp[i-1]+(a[i]>0?1:a[i]==0?0:-1),ask(pre[i]-1)+i);
		add(pre[i],dp[i]-i);
	}
	printf("%d\n",dp[n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}