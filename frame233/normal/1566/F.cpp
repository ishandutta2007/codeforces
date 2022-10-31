#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;typedef long long ll;
ll a[N],f[N],g[N];
struct node{ll l,r;}b[N],c[N],d[N];
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	std::sort(a+1,a+n+1),a[++n]=1e12;
	for(int i=1;i<=m;++i){
		read(b[i].l,b[i].r);
		if(*std::lower_bound(a+1,a+n+1,b[i].l)<=b[i].r)--i,--m;
	}
	std::sort(b+1,b+m+1,[&](const node &a,const node &b){return a.l==b.l?a.r<b.r:a.l>b.l;});
	int mn=2e9,_m=0;
	for(int i=1;i<=m;++i)if(b[i].r<mn)c[++_m]=b[i],mn=b[i].r;
	m=_m,a[0]=-1e12,std::sort(c+1,c+m+1,[&](const node &a,const node &b){return a.l<b.l;});
	memset(f,63,(n+3)<<3),f[0]=0,memset(g,63,(n+3)<<3),g[0]=0;
	for(int i=1,j=1;i<=n;++i){
		int p=0;d[++p]={a[i-1],a[i]};
		while(j<=m&&c[j].r<=a[i])d[++p]=c[j++];
		d[++p]={a[i-1],a[i]};
		for(int t=1;t<p;++t){
			ll l1=d[t].l-a[i-1],l2=a[i]-d[t+1].r,tmp=std::min(f[i-1]+l1,g[i-1]+l1*2);
			chmin(f[i],tmp+l2*2),chmin(g[i],tmp+l2);
		}
	}
	printf("%lld\n",std::min(f[n],g[n]));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}