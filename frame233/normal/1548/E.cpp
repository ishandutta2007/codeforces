#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;
int st[N],mx[N],a[N],b[N],na[N],nb[N],t1[N],t2[N];
void init(int *a,int *ans,int n){
	memset(ans,63,(n+3)<<2);
	for(int i=1,top=0;i<=n;++i){
		int o=a[i];while(top&&a[i]<a[st[top]])chmax(o,mx[top--]);
		if(top)chmin(ans[i],o);
		st[++top]=i,mx[top]=o;
	}
	for(int i=n,top=0;i>=1;--i){
		int o=a[i];while(top&&a[i]<=a[st[top]])chmax(o,mx[top--]);
		if(top)chmin(ans[i],o);
		st[++top]=i,mx[top]=o;
	}
}
int c[N];
void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){int ans=0;for(;x>0;x-=lowbit(x))ans+=c[x];return ans;}
int main(){
	int n,m,x;read(n,m,x);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	init(a,na,n),init(b,nb,m),std::iota(t1+1,t1+n+1,1),std::iota(t2+1,t2+m+1,1);
	std::sort(t1+1,t1+n+1,[&](int x,int y){return a[x]<a[y];}),std::sort(t2+1,t2+m+1,[&](int x,int y){return nb[x]<nb[y];});
	long long ans=0;
	for(int i=1,cur=m;i<=n;++i){
		while(cur&&a[t1[i]]+nb[t2[cur]]>x)add(b[t2[cur--]],1);
		ans+=ask(x-a[t1[i]])-ask(x-na[t1[i]]);
	}
	printf("%lld\n",ans);
	return 0;
}