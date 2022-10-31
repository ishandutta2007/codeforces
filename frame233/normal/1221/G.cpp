#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=45;typedef long long ll;
ll e[N];int sum[1<<20],siz[N],fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int FA[N+N];int FIND(int x){return x==FA[x]?x:FA[x]=FIND(FA[x]);}
int main(){
	int n,m;read(n,m);if(!m)return puts("0"),0;
	std::iota(FA,FA+n+n,0),std::iota(fa,fa+N,0);
	for(int i=1,x,y;i<=m;++i)read(x,y),--x,--y,e[x]|=1LL<<y,e[y]|=1LL<<x,FA[FIND(x+n)]=FIND(y),FA[FIND(x)]=FIND(y+n),fa[find(x)]=find(y);
	for(int i=0;i<n;++i)++siz[find(i)];
	int cnt=0;for(int i=0;i<n;++i)cnt+=fa[i]==i;
	ll ans=1LL<<n;int hf=n>>1;
	for(int st=0;st<1<<hf;++st){
		bool flag=0;for(int i=0;i<hf;++i)if(st>>i&1)flag|=e[i]&st;
		if(!flag)++sum[st];
	}
	for(int i=0;i<hf;++i)for(int j=0;j<1<<hf;++j)if(j>>i&1)sum[j]+=sum[j^(1<<i)];
	for(int st=0;st<1<<(n-hf);++st){
		int all=0;bool flag=0;for(int i=hf;i<n;++i)if(st>>(i-hf)&1)flag|=(e[i]>>hf)&st,all|=e[i];
		all&=(1<<hf)-1;if(!flag)ans-=2*sum[(1<<hf)-1-all];
	}
	ans-=(1LL<<cnt);
	int tot=0;for(int i=0;i<n;++i)if(fa[i]==i&&siz[i]==1)++tot;
	ans+=2LL<<tot;
	bool flag=1;for(int i=0;i<n;++i)flag&=FIND(i)!=FIND(i+n);
	if(flag)ans+=1LL<<cnt;
	printf("%lld\n",ans);
	return 0;
}