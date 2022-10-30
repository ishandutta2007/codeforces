#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void ADD(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void SUB(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int a[N],t[N],f[N],g[N],n;std::vector<int> v[N];
struct BIT1{
	int c[N];
	void add(int x,int C){for(;x<=n;x+=lowbit(x))ADD(c[x],C);}
	int ask(int x){int ans=0;for(;x;x-=lowbit(x))ADD(ans,c[x]);return ans;}
}tr1,TR1;
struct BIT2{
	int c[N];
	void add(int x,int C){for(;x;x-=lowbit(x))ADD(c[x],C);}
	int ask(int x){int ans=0;for(;x<=n;x+=lowbit(x))ADD(ans,c[x]);return ans;}
}tr2;
int dp[N];
void MAIN(){
	read(n);for(int i=1;i<=n;++i)read(a[i]),t[i]=a[i];
	for(int i=0;i<=n;++i)v[i].clear();
	std::sort(t+1,t+n+1);int pos=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t,v[a[i]].pb(i);
	for(int i=1;i<=n;++i){
		f[i]=(tr1.ask(a[i]-1)+1)%mod;
		g[i]=TR1.ask(a[i]-1),ADD(g[i],f[i]);
		tr1.add(a[i],f[i]),TR1.add(a[i],g[i]);
	}
	memset(tr1.c,0,(n+3)<<2),memset(TR1.c,0,(n+3)<<2);
	int mx=0,ans=0;
	for(int i=n;i>=1;--i){
		ADD(ans,g[i]);
		if(a[i]>=mx){
			SUB(ans,f[i]),tr2.add(i,1);
			for(int j=a[i]-1;j>=mx;--j){
				for(auto it:v[j])if(it<=i){
					dp[it]=tr2.ask(it);
					if(it==i)ADD(dp[it],1);
					SUB(ans,1LL*dp[it]*f[it]%mod);
					tr2.add(it,dp[it]);
				}
			}
			tr2.add(i,mod-1);
			for(int j=a[i]-1;j>=mx;--j)for(auto it:v[j])if(it<=i)tr2.add(it,mod-dp[it]);
			mx=a[i];
		}
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}