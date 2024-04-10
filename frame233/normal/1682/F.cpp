#include<bits/stdc++.h>
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=200005,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
int a[N],b[N],t[N],ans[N];ll pre[N];
struct BIT{
	int c[N];void clear(){memset(c,0,sizeof(c));}
	void upd(int x,int C){++x;for(;x<N;x+=lowbit(x))add(c[x],C);}
	int ask(int x){++x;int ans=0;for(;x;x-=lowbit(x))add(ans,c[x]);return ans;}
	inline int ask(int l,int r){int ans=ask(r);sub(ans,ask(l-1));return ans;}
}tr1,tr2;
struct node{int l,r,id;};std::vector<node> Q[N];
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),t[i]=i;
	for(int i=1;i<=n;++i)read(b[i]),pre[i]=pre[i-1]+b[i];
	std::sort(t,t+n+1,[&](int x,int y){return pre[x]<pre[y];});
	for(int i=1,l,r;i<=q;++i)read(l,r),Q[l-1].pb({l,r,i});
	for(int _=0;_<=n;++_){
		int i=t[_];
		for(const auto &it:Q[i]){
			add(ans[it.id],1LL*tr1.ask(it.l,it.r-1)*(pre[i]%mod+mod)%mod);
			sub(ans[it.id],tr2.ask(it.l,it.r-1));
		}
		tr1.upd(i,a[i+1]-a[i]),tr2.upd(i,1LL*(a[i+1]-a[i])*(pre[i]%mod+mod)%mod);
	}
	tr1.clear(),tr2.clear();
	for(int _=n;_>=0;--_){
		int i=t[_];
		for(const auto &it:Q[i]){
			add(ans[it.id],tr2.ask(it.l,it.r-1));
			sub(ans[it.id],1LL*tr1.ask(it.l,it.r-1)*(pre[i]%mod+mod)%mod);
		}
		tr1.upd(i,a[i+1]-a[i]),tr2.upd(i,1LL*(a[i+1]-a[i])*(pre[i]%mod+mod)%mod);
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}