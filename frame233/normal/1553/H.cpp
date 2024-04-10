#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=(1<<19)+5,inf=1e9;
int pool[N*20*3],*P=pool;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int *mn[N<<1],*mx[N<<1],*ans[N<<1],dep[N<<1];bool _[N];
void build(int l,int r,int u){
	mn[u]=P,P+=r-l+1,mx[u]=P,P+=r-l+1,ans[u]=P,P+=r-l+1;
	if(l==r){
		if(_[l])mn[u][0]=0,mx[u][0]=0,ans[u][0]=inf;
		else mn[u][0]=inf,mx[u][0]=-inf,ans[u][0]=inf;
		return;
	}
	int mid=(l+r)>>1;
	dep[ls(u)]=dep[u]-1,dep[rs(u)]=dep[u]-1;
	build(l,mid,ls(u)),build(mid+1,r,rs(u));
	int ch[2]={ls(u),rs(u)},M=(1<<(dep[u]-1))-1;
	for(int i=0;i<1<<dep[u];++i){
		int o=i>>(dep[u]-1)&1;
		mn[u][i]=std::min(mn[ch[o]][i&M],mn[ch[!o]][i&M]+(1<<(dep[u]-1)));
		mx[u][i]=std::max(mx[ch[o]][i&M],mx[ch[!o]][i&M]+(1<<(dep[u]-1)));
		ans[u][i]=std::min({ans[ch[0]][i&M],ans[ch[1]][i&M],abs(mx[ch[o]][i&M]-(mn[ch[!o]][i&M]+(1<<(dep[u]-1))))});
	}
}
int main(){
	int n,k;read(n,k);
	for(int i=1,x;i<=n;++i)read(x),_[x]=true;
	dep[1]=k,build(0,(1<<k)-1,1);
	for(int i=0;i<1<<k;++i)printf("%d%c",ans[1][i]," \n"[i+1==(1<<k)]);
	return 0;
}