#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template<typename _Tp>inline void chmin(_Tp &a,_Tp b){a=a<b?a:b;}
const int N=50005,B=250;typedef unsigned int uint;
int a[N],b[N],bel[N],L[N/B+5],R[N/B+5],cur;uint f[N/B+5][N],g[N],ans[N/B+5];int tag[N/B+5];
inline uint calc(int x,int y){int g=std::gcd(x,y);return 1u*(x/g)*(y/g);}
void pushdown(int id){
	if(tag[id]){
		for(int i=L[id];i<=R[id];++i)a[i]=tag[id];
		tag[id]=0;
	}
}
void rebuild(int id){
	uint ans=3e9;for(int i=L[id];i<=R[id];++i)ans=std::min(ans,calc(a[i],b[i]));
	::ans[id]=ans;
}
void upd(int l,int r,int val){
	if(bel[l]==bel[r]){
		pushdown(bel[l]);
		for(int i=l;i<=r;++i)a[i]=val;
		return rebuild(bel[l]);
	}
	int lb=bel[l],rb=bel[r];
	for(int i=lb+1;i<rb;++i)ans[i]=f[i][val],tag[i]=val;
	pushdown(lb);for(int i=l;i<=R[lb];++i)a[i]=val;
	rebuild(lb);
	pushdown(rb);for(int i=L[rb];i<=r;++i)a[i]=val;
	rebuild(rb);
}
uint ask(int l,int r){
	if(bel[l]==bel[r]){
		uint ans=3e9;pushdown(bel[l]);
		for(int i=l;i<=r;++i)ans=std::min(ans,calc(a[i],b[i]));
		rebuild(bel[l]);return ans;
	}
	int lb=bel[l],rb=bel[r];uint ans=3e9;
	for(int i=lb+1;i<rb;++i)chmin(ans,::ans[i]);
	for(int i=l;i<=R[lb];++i)chmin(ans,calc(tag[lb]?tag[lb]:a[i],b[i]));
	for(int i=L[rb];i<=r;++i)chmin(ans,calc(tag[rb]?tag[rb]:a[i],b[i]));
	return ans;
}
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int l=1,r=B;l<=n;l+=B,r+=B){
		r=std::min(r,n),++cur,L[cur]=l,R[cur]=r;
		for(int i=l;i<=r;++i)bel[i]=cur;
		for(int i=0;i<N;++i)g[i]=f[cur][i]=3e9;
		for(int i=l;i<=r;++i)chmin(g[b[i]],(uint)b[i]);
		for(int i=1;i<N;++i)for(int j=i*2;j<N;j+=i)chmin(g[i],g[j]);
		for(int i=1;i<N;++i)if(g[i]<1e9){uint tmp=g[i]/i;for(int j=i,t=1;j<N;j+=i,++t)chmin(f[cur][j],tmp*t);}
		rebuild(cur);
	}
	int opt,l,r,x;
	while(q--){
		read(opt,l,r);
		if(opt==1)read(x),upd(l,r,x);
		else printf("%u\n",ask(l,r));
	}
	return 0;
}